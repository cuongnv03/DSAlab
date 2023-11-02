#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
//str[strlen(str)-1] = '\0';

typedef struct kienhang{
    char productid[21];
    float length;
    float width;
    float height;
    float weight;
    int deliver;
    int cuocphi;
    int er;
}kienhang;


int PressAnyKey(){
    printf("\n\nBam phim bat ky de tiep tuc...");
    _getch();
    system("cls");
}

int nhapN(kienhang kh[],int n,int s){
    int i;
    for(i=s; i<s+n; i++){
        printf("Nhap ma kien hang so %d: ",i+1);
		fseek(stdin,0,SEEK_END);
		fgets(kh[i].productid,21,stdin);
		kh[i].productid[strlen(kh[i].productid)-1]='\0';
		while ((strlen(kh[i].productid)<8)||(strlen(kh[i].productid)>20)){
            printf("\nNhap lai ma kien hang so %d (ma kien hang co do dai tu 8 den 20 ky tu): ",i+1);
            fseek(stdin,0,SEEK_END);
            fgets(kh[i].productid,21,stdin);
            kh[i].productid[strlen(kh[i].productid)-1]='\0';
		}
        printf("Nhap chieu dai (cm) kien hang so %d:",i+1);
        scanf("%f",&kh[i].length);
        printf("Nhap chieu rong (cm) kien hang so %d: ",i+1);
        scanf("%f",&kh[i].width);
        printf("Nhap chieu cao(cm) kien hang so %d: ",i+1);
        scanf("%f",&kh[i].height);
        printf("Nhap trong luong tinh(kg) kien hang so %d: ",i+1);
        scanf("%f",&kh[i].weight);
        printf("Nhap loai van chuyen kien hang so %d (chuyen nhanh thi nhap 0, chuyen thuong thi nhap 1): ",i+1);
        scanf("%d",&kh[i].deliver);
    }
}
int mini(float a,float b,float c){
    float min;
    min=a;
    if (min>b)
        min=b;
    else min=a;
    if (min>c)
        min=c;
    else min=a;
    return min;
}
int maxi(float a,float b,float c){
    float max;
    max=a;
    if (max<b)
        max=b;
    else max=a;
    if (max<c)
        max=c;
    else max=a;
    return max;
}
int intuchoi(kienhang kh[],int n){
    printf("\nChi tiet kien hang bi tu choi");
    printf("\n=============================");
    printf("\nMa kien hang\t\tLy do tu choi");
    int count=0;
    for (int i=0;i<n;i++){
        if (mini(kh[i].length,kh[i].width,kh[i].height)<10){
            kh[i].er=1;
            printf("\n%s",kh[i].productid);
            printf("\t\tER%d",kh[i].er);
            count++;}
        else if (maxi(kh[i].length,kh[i].width,kh[i].height)>150){
            kh[i].er=2;
            printf("\n%s",kh[i].productid);
            printf("\t\tER%d",kh[i].er);
            count++;}
        else if (kh[i].weight>30){
            kh[i].er=3;
            printf("\n%s",kh[i].productid);
            printf("\t\tER%d",kh[i].er);count++;}
    }
}
int quydoitrongluong(kienhang kh[],int n){
    float sum,tich;
    for (int i=0;i<n;i++){
        sum=kh[i].height+kh[i].length+kh[i].width;
        tich=kh[i].height*kh[i].length*kh[i].width;
        if (sum<80)
            kh[i].weight=kh[i].weight+0;
        else{
            if (kh[i].deliver==1)
                kh[i].weight=maxi(kh[i].weight,tich/6000,0);
            if (kh[i].deliver==0)
                kh[i].weight=maxi(kh[i].weight,tich/4000,0);
        }
        printf("\nTrong luong quy doi tinh phi cua kien hang thu %d la: %f",i+1,kh[i].weight);
    }
}
int tinhtien(kienhang kh[],int n){
    for (int i=0;i<n;i++){
            if ((kh[i].er!=1)&&(kh[i].er!=2)&&(kh[i].er!=3)){
        if (kh[i].weight<=3){
            if (kh[i].deliver==1)
                kh[i].cuocphi=16500;
            if (kh[i].deliver==0)
                kh[i].cuocphi=22000;
        }
        else{
            float x;
            x=(kh[i].weight-3)/0.5;
            int y=(int) x;
            if (kh[i].deliver==1)
                kh[i].cuocphi=16500+y*2500;
            if (kh[i].deliver==0)
                kh[i].cuocphi=22000+y*2500;
        }
    }
    }
}
int intinhtien(kienhang kh[],int n){
    printf("\nMa kien\t\tCan nang tinh phi\t\tHinh thuc van chuyen\t\tCuoc  phi");
    for (int i=0;i<n;i++){
        if ((kh[i].er!=1)&&(kh[i].er!=2)&&(kh[i].er!=3)){
        printf("\n%s",kh[i].productid);
        printf("\t\t%f",kh[i].weight);
            if (kh[i].deliver==1)
                printf("\t\tChuyen thuong");
            if (kh[i].deliver==0)
                printf("\t\tChuyen nhanh");
        printf("\t\t%d",kh[i].cuocphi);
    }
}
}
int tongtien(kienhang kh[],int n){
    int tong=0;
    for (int i=0;i<n;i++){
            if ((kh[i].er!=1)&&(kh[i].er!=2)&&(kh[i].er!=3)){
        tong=tong+kh[i].cuocphi;}
    }
    printf("\nTong tien cuoc: %d",tong);
    printf("\nVAT: %d",(int)(0.08*tong));
    printf("\nTong chi phi: %d",tong+(int)(tong*0.08));
}
int main(){
    kienhang kh[MAX];
    int c,soluongkienhang=0;
    while(1){
        printf("CHUONG TRINH QUAN LY GUI HANG TAI BUU CUC\n");
        printf("--------------------------MENU----------------------------\n");
        printf("--  1. Nhap thong tin kien hang can gui.                --\n");
        printf("--  2. In kien hang bi tu choi.                         --\n");
        printf("--  3. Tinh trong luong quy doi cua mot kien hang.      --\n");
        printf("--  4. Tinh tien hang dua tren trong luong tinh cuoc.   --\n");
        printf("--  5. In cac don hang hop le.                          --\n");
        printf("--  6. Tinh tong tien khach hang phai tra.              --\n");
        printf("--  7. Thoat chuong trinh.                              --\n");
        printf("Nhap tuy chon: ");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("\n1. Nhap thong tin kien hang can gui.");
                int n;
                do{
                    printf("\nSo luong kien hang can gui: ");
                    scanf("%d",&n);
                } while ((n<=0)||(n>=101));
                nhapN(kh,n,soluongkienhang);
                printf("\nNhap %d kien hang thanh cong!\n",n);
                printf("\nHien tai co %d kien hang.",soluongkienhang+n);
                soluongkienhang=soluongkienhang+n;
                PressAnyKey();
                break;
            case 2:
                if(soluongkienhang > 0){
                    printf("\n2. In kien hang bi tu choi.");
                    intuchoi(kh,soluongkienhang);
                }else{
                    printf("\nDanh sach kien hang dang trong!");
                }
                printf("\nTong so: %d",soluongkienhang);
                PressAnyKey();
                break;
            case 3:
                if(soluongkienhang > 0){
                    printf("\n3. Tinh trong luong quy doi cua mot kien hang.");
                    quydoitrongluong(kh,soluongkienhang);
                    printf("\nDa tinh xong trong luong quy doi cua kien hang.");
                }else{
                    printf("\nDanh sach kien hang dang trong!");
                }
                printf("\nTong so: %d",soluongkienhang);
                PressAnyKey();
                break;
            case 4:
                                if(soluongkienhang > 0){
                    printf("\n4. Tinh tien hang dua tren trong luong tinh cuoc.");
                    tinhtien(kh,soluongkienhang);
                    printf("\nDa tinh xong cuoc phi cua kien hang.");
                }else{
                    printf("\nDanh sach kien hang dang trong!");
                }
                printf("\nTong so: %d",soluongkienhang);
                PressAnyKey();
                break;
            case 5:
                                if(soluongkienhang > 0){
                    printf("\n5. In cac don hang hop le.");
                    intinhtien(kh,soluongkienhang);
                }else{
                    printf("\nDanh sach kien hang dang trong!");
                }
                printf("\nTong so: %d",soluongkienhang);
                PressAnyKey();
                break;
            case 6:
                                                if(soluongkienhang > 0){
                    printf("\n6. Tinh tong tien khach hang phai tra.");
                    tongtien(kh,soluongkienhang);
                }else{
                    printf("\nDanh sach kien hang dang trong!");
                }
                printf("\nTong so kien hang da nhan: %d",soluongkienhang);
                PressAnyKey();
                break;
            case 7:
                printf("\nBan da chon thoat chuong trinh!");
                _getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nHay chon chuc nang trong hop menu.");
                break;
        }
    }
}
