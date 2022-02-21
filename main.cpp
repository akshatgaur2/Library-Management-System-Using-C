/* Coded by:-
Akshat Gaur
RA1911027010051
CSE-BD H-2
1009
PPS Assignment */
#include <stdio.h>
#include <string.h>
struct Checkout_date
{
    int date,month,year;
};
struct return_date
{
    int date,month,year;
};
struct student_details
{
    char name[20],address[50];
    long phone;
    struct Checkout_date D[100];
    struct return_date RD[100];
    };
    struct book_details
    {
    long Book_no;
    char Book_title[30],Author[15];
    char publisher[30];
    int Year_of_publication;
    char subject[15];
    struct student_details S[100];
    int status;
    }B[2700];

int a,b,i=0,n=0;int whatuwannado() //checked
{
    printf("Welcome!\n");
    printf("Please choose the following options:\n1 = Add new books\n");
    printf("2 = Search the library by book number, author, title, subject, keywords\n");
    printf("3 = Remove outdated books (all books older than 15 years)\n");
    printf("4 = Checkout books\n5 = return book\n6 = End Programme\n");
    scanf("%d",&a);
    return a;
}
int add_new_books() //Checked
{
    printf("Please enter following details:\n");
    printf("Book Number: "); scanf("%ld",&B[i].Book_no);
    printf("Book Title: "); scanf(" %[^\n]%*c",B[i].Book_title);
    printf("Author: "); scanf(" %[^\n]%*c",B[i].Author);
    printf("Publisher: "); scanf(" %[^\n]%*c",B[i].publisher);
    printf("Year of Publiaction: "); scanf("%d",&B[i].Year_of_publication);
    printf("Subject: "); scanf(" %[^\n]%*c",B[i].subject);
    printf("Book status: Available\n"); B->status=1;
    i++;
}
void search_book_no() //Checked
{
    long no;
    printf("Please enter the Book Number: "); scanf("%ld",&no);
    for(int j=0;j<=i;j++)
    {
        if(no==B[j].Book_no)
        {
            printf("Here are the details:\n");
            printf("Book Number: %ld",B[j].Book_no);
            printf("\nBook Title: %s",B[j].Book_title);
            printf("\nAuthor: %s",B[j].Author);
            printf("\nPublisher: %s",B[j].publisher);
            printf("\nYear of Publiaction: %d",B[j].Year_of_publication);
            printf("\nSubject: %s\n",B[j].subject);
            if(B[j].status==2)
            {
                printf("Current status: Unavailable (Already issued by someone.)\n");
            }
            else if(B[j].status==3)
            {
                printf("Current status: Unavailable (The book is outdated!)\n");
            }
            else if(B[j].status==1)
            {
                printf("Current status: Available\n");
            }
            break;
        }
    }
}
void search_author()
{
    char author[30];
    int r=-1;
    printf("Please enter the name of author: "); scanf(" %[^\n]%*c",author);
    for(int j=0;j<=i;j++)
    {
        r=strcmp(author,B[j].Author);
        if(r==0)
        {
            printf("Here are the details:\n");
            printf("Book Number: %ld",B[j].Book_no);
            printf("\nBook Title: %s",B[j].Book_title);
            printf("\nAuthor: %s",B[j].Author);
            printf("\nPublisher: %s",B[j].publisher);
            printf("\nYear of Publication: %d",B[j].Year_of_publication);
            printf("\nSubject: %s",B[j].subject);
            if(B[j].status==2)          printf("\nCurrent status: Unavailable (Already issued by someone.)\n");
            else if(B[j].status==3)     printf("\nCurrent status: Unavailable (The book is outdated!)\n");
            else if(B[j].status==1)     printf("\nCurrent status: Available\n");
        break;
        }
    }
}

void search_title() //Checked
{
    char title[20];
    int r=-1;
    printf("Please enter the Book Title: "); scanf(" %[^\n]%*c",title);
    for(int j=0;j<=i;j++)
    {
        r=strcmp(title,B[j].Book_title);
        if(r==0)
        {
            printf("Here are the details:\n");
            printf("Book Number: %ld",B[j].Book_no);
            printf("\nBook Title: %s",B[j].Book_title);
            printf("\nAuthor: %s",B[j].Author);
            printf("\nPublisher: %s",B[j].publisher);
            printf("\nYear of Publication: %d",B[j].Year_of_publication);
            printf("\nSubject: %s\n",B[j].subject);
            if(B[j].status==2)
            {printf("Current status: Unavailable (Already issued by someone.)\n");}
            else if(B[j].status==3)
            {printf("Current status: Unavailable (The book is outdated!)\n");}
            else if(B[j].status==1)
            {printf("Current status: Available\n");}
        break;
        }
    }
}
void search_subject() //checked
{
    char sub[20];
    int r=-1;
    printf("Please enter the Subject: "); scanf(" %[^\n]%*c",sub);
    for(int j=0;j<=i;j++)
    {
        r=strcmp(sub,B[j].subject);
        if(r==0)
        {
            printf("Here are the details:\n");
            printf("Book Number: %ld",B[j].Book_no);
            printf("\nBook Title: %s",B[j].Book_title);printf("\nAuthor: %s",B[j].Author);
            printf("\nPublisher: %s",B[j].publisher);
            printf("\nYear of Publication: %d",B[j].Year_of_publication);
            printf("\nSubject: %s",B[j].subject);
            if(B[j].status==2)
            {printf("\nCurrent status: Unavailable (Already issued by someone.)\n");}
            else if(B[j].status==3)
            {printf("\nCurrent status: Unavailable (The book is outdated!)\n");}
            else if(B[j].status==1)
            {printf("\nCurrent status: Available\n");}
            break;
        }
    }
}
void search_keywords()
{
    char Key[15];
    printf("Please enter the keyword: "); scanf("%s",Key);
    int r=-1,t=-1,s=-1,p=-1;
    for(int j=0;j<=i;j++)
    {
        for (char *p1 = strtok(B[j].Book_title," "); p1 != '\0'; p1 = strtok(NULL, " ")) //checked
        {
            t=strcmp(p1,Key);
            if(t==0)
            {
                printf("Here are the details:\n");
                printf("Book Number: %ld",B[j].Book_no);
                printf("\nBook Title: %s",B[j].Book_title);
                printf("\nAuthor: %s",B[j].Author);
                printf("\nPublisher: %s",B[j].publisher);
                printf("\nYear of Publication: %d",B[j].Year_of_publication);
                printf("\nSubject: %s",B[j].subject);
                if(B[j].status==2)
                {printf("\nCurrent status: Unavailable (Already issued by someone.)\n");}
                else if(B[j].status==3)
                {printf("\nCurrent status: Unavailable (The book is outdated!)\n");}
                else if(B[j].status==1)
                {printf("\nCurrent status: Available\n");}
            }
        }
        for (char *p2 = strtok(B[j].Author," "); p2 != '\0'; p2 = strtok(NULL, " "))
        {
            r=strcmp(p2,Key);
            if(r==0)
            {
                printf("Here are the details:\n");
                printf("Book Number: %ld",B[j].Book_no);
                printf("\nBook Title: %s",B[j].Book_title);
                printf("\nAuthor: %s",B[j].Author);
                printf("\nPublisher: %s",B[j].publisher);
                printf("\nYear of Publication: %d",B[j].Year_of_publication);
                printf("\nSubject: %s",B[j].subject);
                if(B[j].status==2)
                {printf("\nCurrent status: Unavailable (Already issued by someone.)\n");}
                else if(B[j].status==3)
                {printf("\nCurrent status: Unavailable (The book is outdated!)\n");}
                else if(B[j].status==1)
                {printf("\nCurrent status: Available\n");}
            }
        }
        for (char *p3 = strtok(B[j].publisher," "); p3 != '\0'; p3 = strtok(NULL, " "))
        {
            p=strcmp(p3,Key);
            if(p==0)
            {
                printf("Here are the details:\n");
                printf("Book Number: %ld",B[j].Book_no);
                printf("\nBook Title: %s",B[j].Book_title);
                printf("\nAuthor: %s",B[j].Author);
                printf("\nPublisher: %s",B[j].publisher);
                printf("\nYear of Publication: %d",B[j].Year_of_publication);
                printf("\nSubject: %s",B[j].subject);
                if(B[j].status==2)
                {printf("\nCurrent status: Unavailable (Already issued by someone.)\n");}
                else if(B[j].status==3)
                {printf("\nCurrent status: Unavailable (The book is outdated!)\n");}
                else if(B[j].status==1)
                {printf("\nCurrent status: Available\n");}
            }
        }
        for (char *p4 = strtok(B[j].subject," "); p4 != '\0'; p4 = strtok(NULL, " "))
        {
            s=strcmp(p4,Key);
            if(s==0)
            {
                printf("Here are the details:\n");
                printf("Book Number: %ld",B[j].Book_no);
                printf("\nBook Title: %s",B[j].Book_title);
                printf("\nAuthor: %s",B[j].Author);
                printf("\nPublisher: %s",B[j].publisher);
                printf("\nYear of Publication: %d",B[j].Year_of_publication);
                printf("\nSubject: %s",B[j].subject);
                if(B[j].status==2)
                {printf("\nCurrent status: Unavailable (Already issued by someone.)\n");}
                else if(B[j].status==3)
                {printf("\nCurrent status: Unavailable (The book is outdated!)\n");}
                else if(B[j].status==1)
                {printf("\nCurrent status: Available\n");}
            }
        }
    }
}
void search()
{
    printf("Search the library by :\n1 = book number\n2 = author\n3 = title\n4 = subject\n5 = keywords\n");
    scanf("%d",&b);
    switch(b)
    {
        case 1:
        search_book_no();
        break;
        case 2:
        search_author();
        break;
        case 3:
        search_title();
        break;
        case 4:search_subject();
        break;
        case 5:
        search_keywords();
        break;
        default:
        break;
    }
}
void remove_outdated_books() //checked
{
    int y;
    printf("Enter Current year: "); scanf("%d",&y);
    y=y-15;
    for(int j=0;j<i;j++)
    {
        if (B[j].Year_of_publication<y)
        {
            B[j].status=3;
            printf("\nThe Book %s is outdated.\n",B[j].Book_title);
        }
    }
}
void Checkout_books() // checked
{
    long no;
    printf("Please enter the Book Number: "); scanf("%ld",&no);
    for(int j=0;j<=i;j++)
    {
        if(no==B[j].Book_no)
        {
            if(B[j].status==2 || B[j].status==3)
            {
                printf("Sorry this book is unavailable.\n");
            }
            else if(B[j].status==1)
            {
                printf("Please enter the following details: \n");
                printf("Name: "); scanf(" %[^\n]%*c",B[j].S[n].name);
                printf("Address: "); scanf(" %[^\n]%*c",B[j].S[n].address);printf("Phone: "); scanf("%ld",&B[j].S[n].phone);
                printf("Checkout date details: \n");
                printf("date: "); scanf("%d",&B[j].S[n].D[n].date);
                printf("month: "); scanf("%d",&B[j].S[n].D[n].month);
                printf("year: "); scanf("%d",&B[j].S[n].D[n].year);
                printf("Return date details: \n");
                printf("date: "); scanf("%d",&B[j].S[n].RD[n].date);
                printf("month: "); scanf("%d",&B[j].S[n].RD[n].month);
                printf("year: "); scanf("%d",&B[j].S[n].RD[n].year);
                printf("This Book is issued successfully by: %s\n",B[j].S[n].name);
                B[j].status=2;
                printf("Current Book status: Unavailable\n");
                n++;
            }
        }
    }
}
void return_books() //checked
{
    char name[20];int r;
    printf("Please enter your name: "); scanf("%s",name);
    for(int j=0;j<=i;j++)
    {
        for(int k=0;k<=n;k++)
        {
            r=strcmp(name,B[j].S[k].name);
            if(r==0)
            {
                printf("Book details: \nBook Number: %ld",B[j].Book_no);
                printf("\nBook Title: %s",B[j].Book_title);
                printf("\nAuthor: %s",B[j].Author);
                printf("\nIssued by: \nName: %s",B[j].S[k].name);
                printf("\nAddress: %s",B[j].S[k].address);
                printf("\nPhone: %ld",B[j].S[k].phone);
                printf("\nThis book is returned successfully!");
                printf("\nCurrent Book status: Available\n");
                B[j].status=1;
                break;
            }
        }
    }
}
int main()
{
    start:
    a=whatuwannado();
    switch(a)
    {
        case 1:
        add_new_books();
        break;
        case 2:
        search();
        break;
        case 3:
        remove_outdated_books();
        break;
        case 4:
        Checkout_books();
        break;
        case 5:
        return_books();
        break;
        case 6:
        goto end;
        break;
        default:;
    }
    goto start;
    end:
    printf("Programme ended. Have a nice day :-)");
    return 0;
}