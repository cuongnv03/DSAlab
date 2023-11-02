#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct phonebook
{
    char fullname[35];
    char add[50];
     char f_name[35];
     char m_name[30];
    long int contact_no;
    char gender[8];
    char email_add[100];
    char postal_code[20];

    };
void menu();
void gt();
void strt();
void bck();
void add_info();
void list_info();
void update_info();
void delete_info();
void search_info();
int main()
{
    system("color 5f");
    strt();
    return 0;
}
void bck()
{
    strt();
}
void strt()
{
    menu();
}
void menu()
{
    system("cls");
printf("\t\t**********WELCOME TO PHONEBOOK*************");

printf("\n\n\t\t\t  MENU\t\t\n\n");
printf("\t1.Add New   \t2.List   \t3.Exit  \n\t4.Modify \t5.Search\t6.Delete\t\n\n");
printf("\n\tPlease Enter the Number you Want to Choose");
switch(getch())
{
    case '1':

                add_info();
    break;
   case '2': list_info();
    break;
    case '3': exit(0);
    break;
    case '4': update_info();
    break;
    case '5': search_info();
    break;
    case '6': delete_info();
    break;
    default:
                system("cls");
                printf("\nEnter 1 to 6 only");
                printf("\n Enter any key");
                getch();

menu();
}
}
        void add_info()
{
        system("cls");
        FILE *files;
        struct phonebook x;
        files=fopen("project","ab+");
        printf("\n Enter Name: ");
        gt(x.fullname);
        printf("\nEnter the Address: ");
        gt(x.add);
        printf("\nEnter Father Nme: ");
        gt(x.f_name);
        printf("\nEnter Mother Name: ");
        gt(x.m_name);
        printf("\nEnter Contact Number.:");
        scanf("%ld",&x.contact_no);
        printf("Enter Gender:");
        gt(x.gender);
        printf("\nEnter Email Address:");
         gt(x.email_add);
        printf("\nEnter Postal Code:");
        gt(x.postal_code);
        fwrite(&x,sizeof(x),1,files);

      fflush(stdin);
        printf("\nNew Record Has Been Successfully Saved");

fclose(files);

    printf("\n\nEnter any key");

	 getch();
    system("cls");
    menu();
}
void list_info()
{
    struct phonebook x;
    FILE *files;
files=fopen("project","rb");
if(files==NULL)
{
printf("\nfile opening error in listing :");

exit(1);
}
while(fread(&x,sizeof(x),1,files)==1)
{
     printf("\n\n\n YOUR RECORD INFORMATION IS\n\n ");
        printf("\nName=%s\nAdress=%s\nFather name=%s\nMother name=%s\nMobile no=%ld\nSex=%s\nE-mail=%s\nCitizen no=%s",x.fullname,x.add,x.f_name,x.m_name,x.contact_no,x.gender,x.email_add,x.postal_code);

	 getch();
	 system("cls");
}
fclose(files);
 printf("\n Enter any key");
 getch();
    system("cls");
menu();
}
void search_info()
{
    struct phonebook x;
FILE *files;
char name[100];

files=fopen("project","rb");
if(files==NULL)
{
    printf("\n error in opening\a\a\a\a");
    exit(1);

}
printf("\nEnter the Name of Person you want to Search\n");
gt(name);
while(fread(&x,sizeof(x),1,files)==1)
{
    if(strcmp(x.fullname,name)==0)
    {
        printf("\n\tDetail Information About %s",name);
        printf("\nName:%s\naddress:%s\nFather name:%s\nMother name:%s\nMobile no:%ld\nsex:%s\nE-mail:%s\nCitision no:%s",x.fullname,x.add,x.f_name,x.m_name,x.contact_no,x.gender,x.email_add,x.postal_code);
    }
        else
        printf("file not found");

}
 fclose(files);
  printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}
void delete_info()
{
    struct phonebook x;
    FILE *files,*file_temp;
	int fl;
	char name[100];
	files=fopen("project","rb");
	if(files==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");

		}
	else
	{
		file_temp=fopen("temp","wb+");
		if(file_temp==NULL)

            printf("file opaning error");
		else

        {


		printf("Enter CONTACT'S NAME:");
		gt(name);

		fflush(stdin);
		while(fread(&x,sizeof(x),1,files)==1)
		{
			if(strcmp(x.fullname,name)!=0)
				fwrite(&x,sizeof(x),1,file_temp);
			if(strcmp(x.fullname,name)==0)
                fl=1;
		}
	fclose(files);
	fclose(file_temp);
	if(fl!=1)
	{
		printf("NO CONACT'S RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
		{
			remove("project");
			rename("temp.txt","project");
			printf("RECORD DELETED SUCCESSFULLY.");

		}
	}
}
 printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}

void update_info()
{
    int b;
    FILE *files;
    int fl=0;
    struct phonebook x,y;
	char  name[50];
	files=fopen("project","rb+");
	if(files==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
            gt(name);
            while(fread(&x,sizeof(x),1,files)==1)
            {
                if(strcmp(name,x.fullname)==0)
                {



                    printf("\n Enter Name:");
                    gt(y.fullname);
                    printf("\nEnter the Address:");
                    gt(y.add);
                    printf("\nEnter Father Name:");
                    gt(y.f_name);
                    printf("\nEnter Mother Name:");
                    gt(y.m_name);
                    printf("\nEnter Contact Number:");
                    scanf("%ld",&y.contact_no);
                    printf("\nEnter Gender:");
                    gt(y.gender);
                    printf("\nEnter Email Address:");
                    gt(y.email_add);
                    printf("\nEnter Postal Code\n");
                    gt(y.postal_code);
                    fseek(files,sizeof(x),SEEK_CUR);
                    fwrite(&y,sizeof(x),1,files);
                    fl=1;
                    break;



                }
                fflush(stdin);


            }
            if(fl==1)
            {
                printf("\n your data id modified");

            }
            else
            {
                    printf(" \n data is not found");

            }
            fclose(files);
	}
	 printf("\n Enter any key");
	 getch();
    system("cls");
	menu();

}
void gt(char *name)
{

   int l=0,k;
    char o,cha;
    do
    {
        o=getch();
                if(o!=8&&o!=13)
                {
                    *(name+l)=o;
                        putch(o);
                        l++;
                }
                if(o==8)
                {
                    if(l>0)
                    {
                        l--;
                    }
                   // printf("h");
                    system("cls");
                    for(k=0;k<l;k++)
                    {
                        cha=*(name+k);
                        putch(cha);

                    }

                }
    }while(o!=13);
      *(name+l)='\0';
}
