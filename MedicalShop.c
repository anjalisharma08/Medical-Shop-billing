#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

char h;
//for home and back
int top=-1,count=0,j=0;
//for stack

 COORD coord={0,0};

 void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
 //gotoxy


 //for calculating price of medicine
 float price(char medname[50],int q)
{
    float p;
    struct medicinedata
    {
        char mname[30];
        int qty;
        float price;

    }m;
    FILE *f;
    f=fopen("MedicineList.dat","r");
    while(fread(&m,sizeof(m),1,f)!=0)
    {
     if(strcmp(medname,m.mname)==0)
     {
        p=(m.price/m.qty)*q;
        printf("%.2f",p);
        fclose(f);
        return p;
     }
    }
}
//front page
void front()
{

    int i;

    gotoxy(63,8);
    printf("-------------------------------\n");
    gotoxy(64,9);
    printf("WELCOME TO JIIT MEDICAL STORE\n");
    gotoxy(63,10);
    printf("-------------------------------\n\n\n\n");

}
//press any key
void press()
{

  gotoxy(64,15);
    printf("Press any key to continue...");

    getch();

int i,j;
system("cls");
front();
gotoxy(56,15);
printf("\t\t  LOADING.....\n");
gotoxy(64,17);
for(i=1;i<30;i++)
    {
        printf("%c",178);
        for(j=1;j<1e7;j++)
        {
        }
    }
  }
  void printmedicine()
  {
      int i=2;
      float s=0;

      struct medicine
     {
       int sno;
         char mname[30];
         int qty;
         float price;
     }x;
   FILE *fp;
   fp=fopen("bill.dat","r");
   gotoxy(40,18);
printf("S.No\t\t\tMedicine Name\t\t\tQTY.\t\t\tPRICE\n");

   while(fread(&x,sizeof(x),1,fp)!=0)
        {
            gotoxy(40,i+19);
            printf("%d",x.sno);
            gotoxy(64,i+19);
            printf("%s",x.mname);
            gotoxy(96,i+19);
            printf("%d",x.qty);
            gotoxy(120,i+19);
            printf("%.2f",x.price);
            i++;
            s=s+x.price;
        }
    gotoxy(96,i+19);
    printf("Total");
    gotoxy(120,i+19);
    printf("%.2f",s);
    gotoxy(0,39);
     printf("Type ""H"" to goto home page:");
     h=getch();
  }
long long int mno;             //global variables for mobile and name
  char name[50];



  //print bill
void printbill()
{
    system("cls");
    front();
    gotoxy(75,14);
    printf("MEDICINE BILL");
    gotoxy(40,16);
    printf("NAME=%s",name);
    gotoxy(90,16);
    printf("MOBILE NO.=%lld",mno);
    printmedicine();
}


//stores the medicines purchased
 void pmedicine()
 {
     struct med
     {
       int sno;
         char mname[30];
         int qty;
         float price;
     }m;

    FILE *fp;
    fp=fopen("bill.dat","w");
    int i=1;
    int c;
     system("cls");
     front();
     gotoxy(73,12);
     printf("MEDICINE DETAILS");
     gotoxy(40,14);
     printf("Enter Customer Name=");
     scanf("%s",name);
     gotoxy(90,14);
     printf("Enter Mobile Number=");
     scanf("%lld",&mno);


     gotoxy(40,16);
     printf("S.No\t\t\tMedicine Name\t\t\tQTY.\t\t\tPRICE\t\tNext Entry Y/n\n");
char ch='y';
     while(ch=='y' || ch=='Y')
    {    gotoxy(40,i+16);
        m.sno=i;
        printf("%d",i);
        gotoxy(64,i+16);
        scanf("%s",m.mname);


gotoxy(96,i+16);
scanf("%d",&m.qty);
gotoxy(120,i+16);
m.price=price(m.mname,m.qty);
fwrite(&m,sizeof(m),1,fp);
gotoxy(136,i+16);
ch=getche();
getch();
i++;

}
fclose(fp);
     }


//UPDATE


void updateprice()
 {
     FILE *fp;
     system("cls");
     front();
     gotoxy(70,13);
     printf("UPDATE INFORMATION");
      struct medicinedata
    {
        char mname[30];
        int qty;
        float price;

    }m;
    struct medicine
    {
        char mname[30];
        int qty;
        float price;
        struct medicine *next;

    }*head=NULL,*ptr,*temp;
char mod[30];
int qty;
float price;

    fp=fopen("MedicineList.dat","r");

    while(fread(&m,sizeof(m),1,fp)!=0)
    {
       temp=(struct medicine *)malloc(sizeof( struct medicine));
       strcpy(temp->mname,m.mname);
       temp->qty=m.qty;
       temp->price=m.price;
       if(head==NULL)
        head=ptr=temp;
       else
       {
           ptr->next=temp;
           ptr=temp;
           temp->next=NULL;
       }
    }
    fclose(fp);

gotoxy(40,16);
printf("S.NO");

printf("\t\tNAME OF MEDICINE");

printf("\t\tQTY.");

printf("\t\tPRICE");

printf("\t\tNEXT ENTRY Y/N");

char ch='y';
int i=1;
while(ch=='y' || ch=='Y')
{
gotoxy(40,i+16);
printf("%d",i);
gotoxy(56,i+16);
scanf("%s",mod);
gotoxy(88,i+16);
scanf("%d",&qty);
gotoxy(104,i+16);
scanf("%f",&price);
gotoxy(120,i+16);
ch=getche();
ptr=head;
while(ptr!=NULL)
{
    if(strcmp(ptr->mname,mod)==0)
    {
        ptr->qty=qty;
        ptr->price=price;
    }
    ptr=ptr->next;
}

   fp=fopen("MedicineList.dat","w");
   ptr=head;
    while(ptr!=NULL)
    {
       strcpy(m.mname,ptr->mname);
       m.qty=ptr->qty;
       m.price=ptr->price;
       fwrite(&m,sizeof(m),1,fp);
        ptr=ptr->next;
    }
    fclose(fp);

    gotoxy(145,i+16);
    printf("UPDATE SUCCESSFUL");
    i++;
    }
    fclose(fp);
gotoxy(0,39);
printf("B:GO BACK=");
h=getch();
 }

//option 1 ENTER DETAILS OF MEDICINE
 void dofmedicine()
 {
     struct addentry
     {
         char mod[30];
   int qty;
   float price;

     }add;



     FILE *fp;
      fp=fopen("MedicineList.dat","a");
     system("cls");
     front();
     gotoxy(70,13);
     printf("NEW MEDICINE");
     gotoxy(40,16);
printf("S.NO");
printf("\t\tNAME OF MEDICINE");
printf("\t\tQTY.");

printf("\t\tPRICE");

printf("\t\tNEXT ENTRY Y/N");
char ch='y';
int i=1;
while(ch=='y' || ch=='Y')
{
gotoxy(40,i+16);
printf("%d",i);
gotoxy(56,i+16);
scanf("%s",add.mod);
gotoxy(88,i+16);
scanf("%d",&add.qty);
gotoxy(104,i+16);
scanf("%f",&add.price);
gotoxy(120,i+16);
ch=getche();
gotoxy(145,i+16);
    printf("ADDED SUCCESSFULLY");
    fwrite(&add,sizeof(add),1,fp);
i++;
 }
 gotoxy(0,39);
printf("B:GO BACK=");
h=getch();
 fclose(fp);
 }



 //structure for stack
struct dom
{
   // int id;

    char name[30];
    int quantity;
    float price;
}a,stack[100];


//push function
int push(struct dom a)
{
   top++;
   stack[top]=a;
    //count++;
}

//pop function
 int pop()
{ int i=1;
gotoxy(70,13);
     printf("LIST OF MEDICINES");
         gotoxy(40,16);
printf("S.NO");
printf("\t\tNAME OF MEDICINE");
printf("\t\tQTY.");

printf("\t\tPRICE");
    while(top!=-1)
   {
gotoxy(40,i+16);
printf("%d",i);
gotoxy(56,i+16);
printf("%s",stack[top].name);
gotoxy(88,i+16);
printf("%d",stack[top].quantity);
gotoxy(104,i+16);
printf("%.2f",stack[top].price);
    i++;
    top--;
   }
    gotoxy(0,39);
printf("B:GO BACK=");
h=getch();
}


//option 6 Display details of medicine
 void displaydetailsm()
 {

system("cls");
front();
FILE *fp;
fp=fopen("MedicineList.dat","r");
while(fread(&a,sizeof(a),1,fp)!=0)
{
   push(a);

}
pop();
fclose(fp);
 }


//OPTION 3 Search medicine by its id /name/company name
void smedicine()
{
struct supplierdata
    {
        char mname[30];
        char supplier[30];
        int mid;
        int sid;
        char city[30];

    }s;

int c;
system("cls");
front();
 gotoxy(56,13);
 printf("1: \tSearch by name\n\n");
  gotoxy(56,15);
    printf("2: \tSearch by id\n\n");
    gotoxy(56,17);
    printf("3: \tSearch by company name\n\n");
    gotoxy(56,21);
    printf("ENTER YOUR CHOICE= ");
    scanf("%d",&c);
  /*  switch(c)
    {
    case 1:
        {

        }
    }
}*/}



//option 7

void displaydetailss()
{ int i=1;
FILE *fp;
fp=fopen("supplierlist.dat","r");
    system("cls");
    front();
    struct supplierdata
    {
        char mname[30];
        char supplier[30];
        int mid;
        int sid;
        char city[30];

    }s;
    gotoxy(70,13);
     printf("SUPPLIER'S DATA");
            gotoxy(20,16);
printf("S.NO");
printf("\t\tNAME OF SUPPLIER");
printf("\t\tNAME OF MEDICINE.");

printf("\t\tSUPPLIER ID");
printf("\t\tMEDICINE ID");
printf("\t\tCITY");
while(fread(&s,sizeof(s),1,fp)!=0)
{
    gotoxy(20,i+16);
    printf("%d",i);
    gotoxy(40,i+16);
printf("%s",s.supplier);
gotoxy(72,i+16);
printf("%s",s.mname);
gotoxy(104,i+16);
printf("%d",s.sid);
gotoxy(128,i+16);
printf("%d",s.mid);
gotoxy(152,i+16);
printf("%s",s.city);
    i++;
   }
   fclose(fp);
    gotoxy(0,39);
printf("B:GO BACK=");
h=getch();
}


//option 2






int main()
{
    int n;

        system("cls");
    system("color 0e");
    front();
    press();
     home:
     system("cls");
    front();
    gotoxy(56,13);
    printf("1: \tEnter the details of the medicines\n\n");
    gotoxy(56,15);
    printf("2: \tEnter the details of the supplier\n\n");
    gotoxy(56,17);
    printf("3: \tSearch the medicine by its id/name/company name\n\n");
    gotoxy(56,19);
    printf("4: \tSearch the supplier's details by his id/city/name");
    gotoxy(56,21);
    printf("5: \tUpdate the price or quantity of the medicine");
    gotoxy(56,23);
    printf("6: \tDisplay the details of the medicine");
    gotoxy(56,25);
    printf("7: \tDisplay the details of the supplier");
    gotoxy(56,27);
    printf("8: \tPurchase Medicine\n");
    gotoxy(56,29);
    printf("ENTER YOUR CHOICE= ");
    scanf("\n%d",&n);
    switch(n)
    {
       case 1:
           {
               dofmedicine();
                if(h=='b' || h=='B')
                goto home;
            break;
            }
        case 2:
        {
            dofsupplier;
                break;
            }
       /* case 3:
           {
               smedicine();
               break;
            }*/
       // case 4:
         //   {ssupplier();
           //     break;
            //}
       case 5:
          {
            updateprice();
            if(h=='b' || h=='B')
                goto home;
            break;
          }
        case 6:
          {
              displaydetailsm();
              if(h=='b' || h=='B')
                goto home;
            break;
         }
        case 7:
          {
              displaydetailss();
               if(h=='b' || h=='B')
                goto home;
                break;

        }
        case 8:
            {
            pmedicine();
            printbill();
            if(h=='h' || h=='H')
                goto home;
                break;
            }
        default:
            {
            printf("WRONG INPUT");
            break;
    }
    }


    return 0;
}
