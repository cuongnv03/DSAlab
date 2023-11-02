#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "tree.c"

typedef struct
{
    char name[1000]; // ten ham
    int (*func)();   // tinh nang ham
} MenuItem;

FILE *file = NULL;
tree_t tree = NULL;
char filename[] = "booking_orders.txt";      // Sua thanh ten file yeu cau
char filenamewrite[] = "booking_output.txt"; // Sua thanh ten file yeu cau

int tinhnang1()
{
    // Mo file che do doc
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Khong mo duoc file %s\n", filename);
        exit(1);
    }
    // code
    int i, count;
    elmType temp;
    fscanf(file, "%d", &count);
    for (i = 0; i < count; i++)
    {
        fscanf(file, "%s %d %s %s %s %d", temp.maYeuCau, &temp.soLuongNguoi, temp.soPhongTaiKhachSan, temp.maKhachSan, temp.ngayThangNam, &temp.soLuongTreEm);
        InsertNode(temp, &tree);
    }
    fclose(file);
    printf("%d\n", count);
    return 0;
}

int soluongkhonghople(tree_t check)
{
    if (check == NULL)
        return 0;
    int i = soluongkhonghople(check->left) + soluongkhonghople(check->right);
    if (check->element.soLuongNguoi <= check->element.soLuongTreEm)
        i++;
    return i;
}

int tinhnang2()
{
    printf("So luong cac yeu cau khong hop le la: %d\n", soluongkhonghople(tree));
    return 0;
}

int checkdate(char *date)
{
    if (strlen(date) < 10 || strlen(date) > 11)
        return 0;
    int dd, mm, yy;
    dd = (date[0] - '0') * 10 + date[1] - '0';
    mm = (date[3] - '0') * 10 + date[4] - '0';
    yy = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
    if (yy >= 1000 && yy <= 9999)
    {
        // check month
        if (mm >= 1 && mm <= 12)
        {
            // check days
            if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                return 1;
            else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                return 1;
            else if ((dd >= 1 && dd <= 28) && (mm == 2))
                return 1;
            else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
                return 1;
            else
                return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

    return 1;
}

int tinhnang3()
{
    // Tim kiem
    elmType find;
    int i, j;
    char input[11];
    printf("Nhap ma yeu cau ban muon tim: ");
    scanf("%s", find.maYeuCau);
    tree_t result = search(find, tree);
    if (result == NULL)
    { // Neu khong tim thay
        printf("Not found\n");
        // code
    }
    else
    { // Neu tim thay
        printf("%s %d %s %s %s %d\n", result->element.maYeuCau, result->element.soLuongNguoi, result->element.soPhongTaiKhachSan, result->element.maKhachSan, result->element.ngayThangNam, result->element.soLuongTreEm);
    }
    return 0;
}

int tinhnang4()
{
    // Tim kiem
    elmType find;
    int i, j;
    char input[11];
    printf("Nhap ma yeu cau ban muon tim: ");
    scanf("%s", find.maYeuCau);
    tree_t result = search(find, tree);
    if (result == NULL)
    { // Neu khong tim thay
        printf("Not found\n");
        // code
    }
    else
    { // Neu tim thay
        printf("%s %d %s %s %s %d\n", result->element.maYeuCau, result->element.soLuongNguoi, result->element.soPhongTaiKhachSan, result->element.maKhachSan, result->element.ngayThangNam, result->element.soLuongTreEm);
        for (;;)
        {
            printf("Nhap ngay thang nam moi theo dinh dang DD-MM-YYYY: ");
            scanf("%s", input);
            if (checkdate(input) == 0)
                printf("Invalid\n");
            else
                break;
        }
        strcpy(result->element.ngayThangNam, input);
        for (;;)
        {
            printf("Nhap so luong nguoi moi: ");
            scanf("%d", &i);
            printf("Nhap so luong tre em moi: ");
            scanf("%d", &j);
            if (i <= j || i <= 0 || j < 0)
                printf("Invalid\n");
            else
                break;
        }
        result->element.soLuongNguoi = i;
        result->element.soLuongTreEm = j;
        printf("Update\n");
    }
    return 0;
}

int tinhnang5()
{
    // Tim kiem
    elmType find;
    int i, j;
    char input[11];
    printf("Nhap ma yeu cau ban muon tim: ");
    scanf("%s", find.maYeuCau);
    tree_t result = search(find, tree);
    if (result == NULL)
    { // Neu khong tim thay
        printf("Not found\n");
        // code
    }
    else
    { // Neu tim thay
        deleteNode(result->element, &tree);
        printf("Delete\n");
    }
    return 0;
}

int countTree(tree_t check)
{
    if (check == NULL)
        return 0;
    int i = countTree(check->left) + countTree(check->right) + 1;
    return i;
}

void ghiCayVaoFile(FILE *file, tree_t check)
{
    if (check == NULL)
        return;
    fprintf(file, "%s %d %s %s %s %d\n", check->element.maYeuCau, check->element.soLuongNguoi, check->element.soPhongTaiKhachSan, check->element.maKhachSan, check->element.ngayThangNam, check->element.soLuongTreEm);
    ghiCayVaoFile(file, check->left);
    ghiCayVaoFile(file, check->right);
    return;
}

int tinhnang6()
{
    // Mo file che do ghi
    file = fopen(filenamewrite, "w");
    if (file == NULL)
    {
        printf("Khong mo duoc file %s\n", filenamewrite);
        exit(1);
    }
    // code
    int i;
    fprintf(file, "%d\n", countTree(tree));
    ghiCayVaoFile(file, tree);
    printf("%d\n", countTree(tree));
    fclose(file);
    return 0;
}

int tinhnang7()
{
    return 0;
}

int tinhnang8()
{
    return 0;
}

int tinhnang9()
{
    return 0;
}

int thoat()
{
    // Return 1 de doan sau thoat duoc vong lap
    printf("\nCam on ban da su dung chuong trinh.\nThoat chuong trinh...\n\n");
    return 1;
}

int main()
{
    // De y so tinh nang
    MenuItem item[] = {{"Doc du lieu tu file log", tinhnang1},
                       {"Kiem tra so luong yeu cau khong hop le", tinhnang2},
                       {"Tra cuu theo ma yeu cau", tinhnang3},
                       {"Thay doi yeu cau", tinhnang4},
                       {"Huy yeu cau", tinhnang5},
                       {"Luu danh sach yeu cau ra file", tinhnang6},
                       {"Thong ke khach san duoc yeu thich nhat", tinhnang7},
                       {"Ngay khong hop le", tinhnang8},
                       {"Ngay khong hop le", tinhnang9},
                       {"Thoat", thoat}};
    int size = sizeof(item) / sizeof(item[0]); // Kich co menu
    int i;

    for (;;)
    { // Vong lap vo han chay den khi gap thoat thi ket thuc
        printf("\nChuong trinh quan ly dat phong\nVui long chon mot trong cac chuc nang sau\n");
        for (i = 0; i < size; i++)
        {
            printf("[%d] %s\n", i + 1, item[i].name); // In menu
        }

        int luachon;
        printf("\nNhap lua chon: ");
        scanf("%d", &luachon);

        if (luachon < 1 || luachon > size)
        {
            printf("Vui long nhap 1 so tu 1 den %d!\n", size);
            continue; // Neu lua chon khong nam trong kich co thi bo qua
        }
        else if (item[luachon - 1].func())
        {
            // Khi goi den ham thoat thi se thoat vong lap do return 1
            break;
        }
    }
    // Giai phong bo nho cap phat dong
    freeTree(tree);
}
