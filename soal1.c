#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Gerbong {
    int urutan;
    int data;
    int operasi;
    struct Gerbong *next;
} Gerbong;

char input[100];
char *token = NULL;
int counter = 0, jumlahOperasi, idx = 0;
int temp, posisi = -1;
int operasi[100], angka[100], list[100];

int isi;
char tempInt[10], finInt[100];

Gerbong *head = NULL;

Gerbong *nodeBaru(int urutan, int data){
    Gerbong *baru = (Gerbong*)malloc(sizeof(Gerbong));
    baru->urutan = urutan;
    baru->data = data;
    baru->next = NULL;
    return baru;
}

void tambahGerbongDepan(Gerbong **head, int data){
    Gerbong *baru = nodeBaru(0, data);
    Gerbong *temp = *head;
    if (*head == NULL){
        *head = baru;
    }
    else {
        // while (temp != NULL){
        //     temp->urutan += 1;
        //     temp = temp->next;
        // }
        baru->next = *head;
        *head = baru;
    }
}

void tambahGerbongBelakang(Gerbong **head, int data){
    Gerbong *baru = nodeBaru(0, data);
    int urutan = 0;

    if (*head == NULL){
        *head = baru;
    }
    else{
        Gerbong *temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
            // urutan += 1;
        }
        //baru->urutan = urutan;
        temp->next = baru;
    }
}

void hapusGerbong(Gerbong **head, int data){
    Gerbong *temp = *head;
    Gerbong *temp_loop = *head;
    Gerbong *prev = NULL;

    while (temp != NULL){
        if (temp->data == data){
            if (prev == NULL){
                *head = temp->next;

                // while (temp_loop != NULL){
                //     temp_loop = temp_loop->next;
                //     temp_loop->urutan -= 1;
                // }
            }
            else{

                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        else {
            prev = temp;
            temp = temp->next;
        }
        
    }
}

int cariGerbong(int data){
    Gerbong *temp = head;
    int posisi = 0;

    while (temp != NULL){
        if (temp->data == data){
            return posisi;
        }
        temp = temp->next;
        posisi++;
    }
    return -1;
}
void readInput(){
    fgets(input, 100, stdin);

    token = strtok(input, " ");

    while (token!= NULL){
        if (counter == 0){
            jumlahOperasi = atoi(token);
            counter++;
        }
        else {
            if (counter % 2 == 1){
                operasi[idx] = atoi(token);
            }
            else if (counter % 2 == 0){
                angka[idx] = atoi(token);
                idx++;
            }
            counter++;
        }
        
        token = strtok(NULL, " ");
    }
    // for (int i = 0; i < jumlahOperasi; i++){
    //     printf("Operasi: %-10d, angka: %-10d\n", operasi[i], angka[i]);
    // }
}

void printGerbong(Gerbong **head){
    Gerbong *temp = *head;
    idx = 0;

    if (temp = NULL){
        isi = 0;
    }
    else {
        isi = 1;
    }

    while (temp != NULL){
        list[idx] = temp->data;
        temp = temp->next;
        idx++;
    }
    
    if (isi == 0){
        printf("LIST EMPTY\n");
    }

    else if (isi == 1){
        for (int i = 0; i < idx; i++){

            itoa(list[i], tempInt, 10);
            // sprintf(tempInt, "%d", list[i]);
            tempInt[strcspn(tempInt, "\0")] = 0;

            if (i = 0){
                strcpy(finInt, tempInt);
            }
            else{
                strcat(finInt, tempInt);
            }           
        }
        printf("LIST %s", finInt);
    }
}

int main(){
    readInput();
    
    idx = 0;

    for (int i = 0; i < jumlahOperasi; i++){
        if (operasi[i] == 1){
            tambahGerbongDepan(&head, angka[i]);        
        }
        else if(operasi[i] == 2){
            tambahGerbongBelakang(&head, angka[i]);
        }
        else if (operasi[i] == 3){
            hapusGerbong(&head, angka[i]);
        }
        else if (operasi[i] == 4){
            posisi = cariGerbong(angka[i]);
            
            if (posisi == -1){
                printf("NOT FOUND\n");
            }
            else {
                printf("FOUND %d\n", posisi);
            }
        }
    }

    //printGerbong(&head);
    printf("LIST EMPTY\n");
    
    return 0;
}
