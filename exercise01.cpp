/*
Nama Program    : Exercise-01
Nama            : Sharashena Chairani
NPM             : 140810180022
Kelas           : B
Deskripsi       : Membuat program single link listed Pegawai
Tanggal Buat    : 20 Maret 2019
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct ElementList{
    char name[20];
    char divisi[50];
    int gaji;
    ElementList* next;
};

typedef ElementList* pointer;
typedef pointer List;

void createList (List& first);
void createElement (pointer& pBaru);
void insertFirst (List& first, pointer pBaru);
void traversal(List first);
void deleteFirst (List& first, pointer& pHapus);
void insertLast (List& first, pointer pBaru);
void deleteLast (List& first, pointer& pHapus);
main()
{
    pointer p;
    List ElementList;
    int pilih;

    createList(ElementList);
    while(1){
        system("cls");
        cout<<"Pilihan Menu : "<<endl;
        cout<<"1. Insert First "<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Delete First"<<endl;
        cout<<"4. Delete Last"<<endl;
        cout<<"5. Tampilkan data"<<endl;
        cout<<"6. Exit"<<endl;
        cout << "Masukan Pilihan Anda : "; cin>>pilih;
        switch(pilih){
        case 1:
            createElement(p);
            insertFirst(ElementList, p);
            getch();
        break;

        case 2:
            createElement(p);
            insertLast(ElementList,p);
            getch();
        break;

        case 3:
            deleteFirst(ElementList,p);
            getch();
        break;

        case 4:
            deleteLast(ElementList,p);
            getch();
        break;

        case 5:
            traversal(ElementList);
            getch();
        break;

        case 6:
            return 0;
            break;
        }
        system("pause");
    }
}

void createList (List& first){
    first=NULL;
}

void createElement (pointer& pBaru){
    pBaru=new ElementList;
    cout<<"~~~~Silahkan Masukkan Data Pegawai~~~~"<<endl;
    cout<<"Nama     : "; cin>>pBaru->name;cin.ignore();
    cout<<"Divisi   : "; cin.getline(pBaru->divisi, 50);
    cout<<"Gaji     : "; cin>>pBaru->gaji;
    pBaru->next=NULL;
}

void insertFirst (List& first, pointer pBaru){
    if (first==NULL){
        first=pBaru;
    }
    else{
        pBaru->next=first;
        first=pBaru;
    }
}

void traversal(List first){
    pointer pBantu;
    pBantu=first;
    while (pBantu != NULL){
        cout<<"\nNama     : "<<pBantu->name<<endl;
        cout<<"Divisi   : "<<pBantu->divisi<<endl;
        cout<<"Gaji     : "<<pBantu->gaji<<endl;
        pBantu=pBantu->next;
    }
}

void deleteFirst (List& first, pointer& pHapus){
    if(first==NULL){
        pHapus=NULL;
        cout<<"List kosong, tidak ada  yang dihapus"<<endl;
    }
    else if(first->next==NULL){
        pHapus=first;
        first=NULL;
    }
    else {
        pHapus=first;
        first=first->next;
        pHapus->next=NULL;
    }
}

void insertLast (List& first, pointer pBaru){
    pointer last;
    if (first==NULL){
        first=pBaru;
    }
    else {
        last=first;
        while (last->next!=NULL){
            last=last->next;
        }
        last->next=pBaru;
}
}
void deleteLast (List& first, pointer& pHapus){
    pointer last, precLast;
    if (first==NULL){
        pHapus=NULL;
        cout<<"List kosong, tidak ada yang dihapus"<<endl;
    }
    else if(first->next==NULL){
        pHapus=first;
        first=NULL;
    }
    else {
        last=first;
        precLast=NULL;
        while (last->next!=NULL){
            precLast=last;
            last=last->next;
        }
        pHapus=last;
        precLast->next=NULL;
    }
}




