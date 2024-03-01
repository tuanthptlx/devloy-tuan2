
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct SinhVien
{
    int msv;
    char ten[50], lop[50], hanhkiem[50];
    float dtk;
    void Nhap();
    void Xuat();
};

void SinhVien::Nhap()
{
    printf("Nhap msv:");
    scanf("%d", &msv);
    fflush(stdin);
    printf("Nhap ten:");
    gets(ten);
    printf("Nhap lop:");
    gets(lop);
    printf("Nhap hanh kiem:");
    gets(hanhkiem);
    printf("Nhap diem tong ket:");
    scanf("%f", &dtk);
}

void SinhVien::Xuat()
{
    printf("%d, %s, %s, %s %0.2f\n", msv, ten, lop, hanhkiem, dtk);
}

struct node
{
    SinhVien data;
    struct node *next;
};
typedef struct node node;
node *makeNode(SinhVien a)
{
    node *tmp = (node *)malloc(sizeof(node));
    if (tmp == NULL)
    {
        printf("Khong du bo nho cap phat!!\n");
        return NULL;
    }
    tmp->data = a;
    tmp->next = NULL;
}

struct list
{
    node *head = NULL;
    node *tail = NULL;
};

void ChenCuoi(list &a, node *tmp)
{
    if (a.head == NULL)
    {
        a.head = tmp;
        a.tail = tmp;
    }
    else
    {
        a.tail->next = tmp;
        a.tail = tmp;
    }
}

void XoaCuoi(list &a)
{
    if (a.head == NULL)
    {
        printf("Het du lieu de xoa!!\n");
        return;
    }
    node *psau = NULL;
    node *p = a.head;
    while (p->next != NULL)
    {
        psau = p;
        p = p->next;
    }
    if (psau == a.head)
    {
        a.head = NULL;
        a.tail = NULL;
    }
    a.tail = psau;
    psau->next = NULL;
    p->next = NULL;
    free(p);
}

void SVD13CNPM(list a)
{
    while (a.head != NULL)
    {
        if (strcmp(a.head->data.lop, "D13CNPM") == 0)
        {
            a.head->data.Xuat();
        }
        a.head = a.head->next;
    }
    
}

void Xuat(list a)
{
    while (a.head != NULL)
    {
        a.head->data.Xuat();
        a.head = a.head->next;
    }
}

int main()
{  
    list ds;
    int n;
    printf("Nhap so luong sinh vien:");
    scanf("%d",&n);
    fflush(stdin);
    for ( int i = 0; i < n; i++)
    {
        SinhVien tmp;
        tmp.Nhap();
        ChenCuoi(ds, makeNode(tmp));    
    }
    printf("Danh sach vua nhap la:\n");
    Xuat(ds);
    printf("=================================\n");
    printf("Danh sach sinh vien D13CNPM1\n:");
    SVD13CNPM(ds);
    printf("=================================\n");
    XoaCuoi(ds);
    printf("Danh sach sau khi xoa cuoi 1 node:\n");
    Xuat(ds);
}