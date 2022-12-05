#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
//tao cau truc sinh vien
struct SinhVien { 
    char maSV[8]; 
    char hoTen[50]; 
    int gioiTinh; 
    Ngay ngaySinh; 
    char diaChi[100]; 
    char lop[12]; 
    char khoa[7]; 
    };
//tao cau truc danh sach lien ket don
struct Ngay {
    int ngay, thang, nam; 
    }; 
struct Node {  
    Node *link; 
    }; 
struct List { 
    Node *first;
    };
//khoi tao danh sach lien ket don
void Initialize(List *&list)
{
    list=new List;
    list->first=NULL;
}
//nhap thong tin sinh vien
SinhVien *NhapSinhVien()
{
    SinhVien *sv=new SinhVien;
    cout<<"Nhap MSSV:";
    cin>>sv->maSV;
    cin.ignore();
    cout<<"Nhap ho va ten:";
    gets(sv->ten);
    cout<<"Nhap gioi tinh:";
    gets(sv->gioiTinh);
    cout<<"Nhap ngay sinh:";
    gets(sv->ngaySinh);
    cout<<"Nhap dia chi:";
    gets(sv->diaChi);
    cout<<"Nhap lop:";
    gets(sv->lop);
    cout<<"Nhap khoa:";
    gets(sv->khoa);
    return sv;
}
//tao node sinh vien
Node *CreateNode(SinhVien *sv)
{
    Node *pNode=new Node;
    if(pNode!=NULL)
    {
        pNode->data=sv;
        pNode->link=NULL;
    }
    else
    {
        cout<<"cap phat bo nho that bai!!!";
    }
    return pNode;
}
//them node vao cuoi danh sach
void InsertLast(SingleList *&list,SinhVien *sv)
{
    Node *pNode=CreateNode(sv);
    if(list->first==NULL)
    {
        list->first=pNode;
    }
    else
    {
        Node *pTmp=list->first;
         
        while(pTmp->link!=NULL)
        {
            pTmp=pTmp->link;
        }
        pTmp->link=pNode;
    }
}
//hien thi danh sach
void PrintList(SingleList *list)
{
    Node *pTmp=list->first;
    if(pTmp==NULL)
    {
        cout<<"Danh sach rong";
        return;
    }
    while(pTmp!=NULL)
    {
        SinhVien *sv=pTmp->data;
        cout<<sv->ma<<"\t"<<sv->ten<<"\n";
        pTmp=pTmp->link;
    }
}
//sap xep
void SortList(SingleList *&list)
{
    for(Node *pTmp=list->first;pTmp!=NULL;pTmp=pTmp->link)
    {
        for(Node *pTmp2=pTmp->link;pTmp2!=NULL;pTmp2=pTmp2->link)
        {   
            SinhVien *svTmp=pTmp->data;
            SinhVien *svTmp2=pTmp2->data;
            if(svTmp2->maSV<svTmp->maSV)
            {
                int ma=svTmp->maSV;
                char ten[150];
                strcpy(ten,svTmp->hoTen);
                 
                svTmp->maSV=svTmp2->maSV;
                strcpy(svTmp->ten,svTmp2->hoTen);
                svTmp2->maSV=maSV;
                strcpy(svTmp2->hoTen,hoTen);             
            }
        }   
    }
}
int main(int argc, char** argv) {
    SingleList *list;
    Initialize(list);
    SinhVien *teo=NhapSinhVien();
    InsertLast(list,teo);
    SinhVien *ty=NhapSinhVien();
    InsertLast(list,ty);
    SinhVien *bin=NhapSinhVien();
    InsertLast(list,bin);
    PrintList(list);
    SortList(list);
    cout<<"\nSau khi sap xep:";
    PrintList(list);
