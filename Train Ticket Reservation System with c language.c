#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char name[50];
	int tno;
	int num_of_seats;
}pd;
struct creataccount
{
    char id[10],pwd[13];
}newacc;
int k=0,t=0,ky;


void reservation();
void viewdetails();
void cancel();
void printticket(char name[],int,int,float);
void specifictrain(int);
float charge(int,int);
void login();
void creatacc();
int check_existing(char*,char*);





int main()

{
		system("cls");
	printf("\t\t======================================================\n");
	printf("\t\t|                                                    |\n");
	printf("\t\t|        ------------------------------------        |\n");
	printf("\t\t|           TRAIN TICKET RESERVTION SYSTEM           |\n");
	printf("\t\t|        ------------------------------------        |\n");
	printf("\t\t|                                                    |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t======================================================\n\n\n");


	printf(" \n Press any key to start reservation:");

	getch();
    system("cls");
    printf("1.Login in Guest account.\n2.Create an account.\n3.Login in existing account");
    int ch;
    printf("\nEnter the choice-->");
    scanf("%d",&ch);
    if(ch==1)
    {
        login();
    }
    if(ch==2)
    {
        k=1;
        creatacc();
    }
    if(ch==3)
    {
        k=1;
        ky=1;
        login();
    }

	int menu_choice;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Trains");
	printf("\n------------------------");
	printf("\n3>> Cancel Reservation");
	printf("\n------------------------");
	printf("\n4>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			cancel();
			break;
		case 4:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

/*********************************************VIEWDETAILS()*************************************************/


void viewdetails(void)
{
	system("cls");
	printf("\n----------------------------------------------------------------------------------");
	printf("\nTr.No  Name                       Destinations              Charges       Time");
	printf("\n----------------------------------------------------------------------------------");
	printf("\n12676  Kovai Express               Chennai to Coimbatore     Rs.500       9am");
	printf("\n12680  Mumbai Express              Chennai To Mumbai         Rs.500       12pm");
	printf("\n12245  Banglore Express            Chennaie To Bangalore     Rs.450       8am");
	printf("\n22637  West coast Express          Chennai To Mangalore      Rs.450       11am");
	printf("\n21289  Delhi Express               Chennai To Delhi          Rs.600       7am");
	printf("\n12345  Raj Dhani Express(special)  Chennai To Delhi          Rs.1500      9.30am");
	printf("\n----------------------------------------------------------------------------------");

}
pd passdetails;

void reservation(void)
{
    t=1;
	char confirm;
	float charges;

	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	printf("\nEnter Your Name:> ");
    fflush(stdin);
	gets(passdetails.name);
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.tno);
	if(passdetails.tno==12345 || passdetails.tno==21289||passdetails.tno==22637||passdetails.tno==12245||passdetails.tno==12680||passdetails.tno==12676)
	{
		charges=charge(passdetails.tno,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.tno,charges);
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",passdetails.name,passdetails.num_of_seats,passdetails.tno,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Sucessfull!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}



 float charge(int tno,int num_of_seats)
{
		if (tno==12676)
	{
		return(500.0*num_of_seats);
	}
	if (tno==12680)
	{
		return(500.0*num_of_seats);
	}
	if (tno==12245)
	{
		return(450.0*num_of_seats);
	}
	if (tno==22637)
	{
		return(450.0*num_of_seats);
	}
	if (tno==12345)
	{
		return(1500.0*num_of_seats);
	}
	if (tno==21289)
	{
		return(600.0*num_of_seats);
	}
}


void printticket(char name[],int num_of_seats,int tno,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",tno);

	specifictrain(tno);
	printf("\nToatl Fare:\t\t%.2f",charges);
}


void specifictrain(int tno)
{

	if (tno==12676)
	{
		printf("\nTrain:\t\t\tKovai Express");
		printf("\nDestination:\t\tChennai to Kovai");
		printf("\nDeparture:\t\t9am ");
	}
	if (tno==12680)
	{
		printf("\nTrain:\t\t\tChennai Express");
		printf("\nDestination:\t\t Mumbai to Chennai");
		printf("\nDeparture:\t\t12pm");
	}
	if (tno==12245)
	{
		printf("\nTrain:\t\t\tBangalore Express");
		printf("\nDestination:\t\tChennai to Bangalore");
		printf("\nDeparture:\t\t8am");
	}
	if (tno==22637)
	{
		printf("\nTrain:\t\t\tWest Coast Express");
		printf("\nDestination:\t\tChennai to Mangaluru");
		printf("\nDeparture:\t\t11am ");
	}
	if (tno==21289)
	{
		printf("\nTrain:\t\t\tDelhi Express");
		printf("\nDestination:\t\tChennai to Delhi");
		printf("\nDeparture:\t\t7am");
	}
	if (tno==12345)
	{
		printf("\ntrain:\t\t\tRAJ DHANI EXPRESS (Special)");
		printf("\nDestination:\t\tChennai to Delhi");
		printf("\nDeparture:\t\t9.30am ");
	}
}

void login()
{
	int a=0,i=0,key;
    char uname[10],c=' ';
    char pword[10];
    char user[10]="user";
    char pass[10]="pass";
    if(k==0)
    {
        printf("\nDefault :");
        printf("\nuser id:%s\npassword:%s",user,pass);
    }
    do
{

    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s",uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
    i=0;
    if(ky==1)
    {
        key=check_existing(uname,pword);
    }
    else
    {
        key=1;
    }
    if(((strcmp(uname,"user")==0)||(strcmp(uname,newacc.id)==0)) &&((strcmp(pword,"pass")==0)||(strcmp(pword,newacc.pwd)==0))||(key==1))
	{
	printf("  \n\n\n       WELCOME TO RAILWAY RESERVATION SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  YOUR LOGIN IS UNSUCESSFUL");
		a++;

		getch();
		if(a<=2)
        {
		system("cls");
        }
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
		exit(1);
}

void cancel(void)
{
	system("cls");
	if(t==1)
    {
        int trainnum;
        retry:
	    viewdetails();
	    printf("\n-----------------------\n");
		printf("Enter the train number in which you have reserved: \n");
        printf("-----------------------\n");
		fflush(stdin);
		scanf("%i",&trainnum);
		if(passdetails.tno==trainnum)
        {
            specifictrain(trainnum);
            printf("\n\n Your reservation in the above train has been CANCELLED.");
		    getch();
        }
        else
        {
            printf("\nYou have no reservation in the entered train number .");
            printf(" \n Press any key to continue..");
            getch();
            goto retry;
        }
    }
    else
    {
        printf("\nTickets are not reserved.");
        printf(" \n Press any key to continue..");
        getch();
    }

}

void creatacc()
{
    k=1;
    FILE *fptr;
    fptr=fopen("database.txt","a");
    ui:
    printf("\nEnter new user id(mini:5-max:10 characters):");
    scanf("%s",newacc.id);
    if(strlen(newacc.id)<5)
    {
        printf("\nSize of user id is less than 5 character");
        printf(" \n Press any key to continue..");
        getch();
        system("cls");
        goto ui;
    }
    up:
    printf("\nEnter new password(mini:6-max:13 characters):");
    scanf("%s",newacc.pwd);
    if(strlen(newacc.pwd)<5)
    {
        printf("\nSize of password is less than 6 character");
        printf(" \n Press any key to continue..");
        getch();
        system("cls");
        goto up;
    }
    fprintf(fptr,"%s$%s$",newacc.id,newacc.pwd);
    fclose(fptr);
    printf(" \n Press any key to continue..");
    getch();
    system("cls");
	login();

}
int check_existing(char *check_id,char *check_pass)
{

    FILE *fp;
    int i1=0,i2=0;
    fp=fopen("database.txt","r");
    char lst[100][13],chara,arr[100];
    chara=getc(fp);
    int acv=0;
    while(chara!=EOF)
    {
         if(chara!='$')
        {
            lst[i1][i2]=chara;
            i2++;
        }
        else
        {
            lst[i1][i2]='\0';
            i1++;
            i2=0;

        }
        chara=getc(fp);
    }
    fclose(fp);
    for(int cv=0;cv<i1;cv++)
    {

        if(strcmp(lst[cv],check_id)==0&&strcmp(lst[cv+1],check_pass)==0)
        {
            return(1);
        }
    }
    return(0);
}
