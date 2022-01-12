#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

struct sharath_airlines
{
	char passport[10];
	char name[50];
    char destination[50];
	int seat_num;
	char email[50];
	struct sharath_airlines *following;
}
*begin, *stream;
struct sharath_airlines *dummy;

void main()
{
	void reserve(int x), cancel(), display(), savefile();
	int choice;
	begin = stream = NULL;
	int num = 1;
	do
	{	
		printf("\n\n\t\t -------------------------------------------------------------------");
		printf("\n\t\t               Welcome to Sharath's Airline Booking System                   ");
		printf("\n\t\t -------------------------------------------------------------------");
		printf("\n\n\n\t\t Please enter your choice from below (1-4):");
		printf("\n\n\t\t 1.Reservation for a flight");
		printf("\n\n\t\t 2.Cancelling a ticket");
		printf("\n\n\t\t 3.Display the Records");
		printf("\n\n\t\t 4.Exit");
		printf("\n\n\t\t Feel free to contact ");
		printf("\n\n\t\t Enter your choice :");
		scanf("%d", &choice); fflush(stdin);
		system("cls");
		switch (choice)
		{
		case 1:
			reserve(num);
			num++;
			break;
		case 2:
			cancel();
			break;
		case 3:
			display();
			break;
		case 4:
		{
				  savefile();
				  break;
		}
		default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n\n\t PLEASE CHOOSE FROM 1-4");
			printf("\n\n\t Do not forget to chose from 1-4");
		}
		getch();
	} while (choice != 4);
}
void details()
{
	printf("\n\t Enter your passport number:");
	gets(stream->passport); fflush(stdin);   
	printf("\n\t Enter your name:");
	gets(stream->name); fflush(stdin);
	printf("\n\t Enter your email address:");
	gets(stream->email); fflush(stdin);
    printf("\n\t Enter the Destination : ");
    gets(stream->destination); fflush(stdin);
}
void details();

void reserve(int x)
{
	stream = begin;
	if (begin == NULL)
	{
		begin = stream = (struct sharath_airlines*)malloc(sizeof(struct sharath_airlines));
		details();
		stream->following = NULL;
		printf("\n\t Seat booking is successful!");
		printf("\n\t Your seat number is: Seat A-%d", x);
		stream->seat_num = x;
		return;
	}
	else if (x > 30)
	{
		printf("\n\t\t Seats are Full.");
		return;
	}
	else
	{
		while (stream->following)
			stream = stream->following;
		stream->following = (struct sharath_airlines *)malloc(sizeof(struct sharath_airlines));
		stream = stream->following;
		details();
		stream->following = NULL;
		printf("\n\t Seat booking succesful!");
		printf("\n\t Your seat number is: Seat A-%d", x);
		stream->seat_num = x;
		return;
	}
}
void savefile()
{
	FILE *fpointer = fopen("sharath records", "w");
	if (!fpointer)
	{
		printf("\n Error in opening file!");
		return;
		Sleep(800);
	}
	stream = begin;
	while (stream)
	{
		fprintf(fpointer, "%-10s", stream->passport);
		fprintf(fpointer, "%-50s", stream->name);
		fprintf(fpointer, "%-50s", stream->email);
        fprintf(fpointer, "%-50s", stream->destination);
        fprintf(fpointer, "\n");
		stream = stream->following;
	}
	printf("\n\n\t Details have been saved to a file (sharath records)");
	fclose(fpointer);
}
void display()
{
	stream = begin;
	while (stream)
	{
		printf("\n\n Passport Number : %-10s", stream->passport);
		printf("\n      Name : %-50s", stream->name);
		printf("\n      Email address: %-50s", stream->email);
		printf("\n      Seat number: A-%d", stream->seat_num);
        printf("\n      Destination:%-50s", stream->destination);
		printf("\n\n++*=====================================================*++");
		stream = stream->following;
	}
}
void cancel()
{
	stream = begin;
	system("cls");
	char passport[6];
	printf("\n\n Enter Passport Number to delete record:");
	gets(passport); fflush(stdin);
	if (strcmp(begin->passport, passport) == 0)
	{
		dummy = begin;
		begin = begin->following;
		free(dummy);
		printf(" Your ticket has been deleted");
		Sleep(800);
		return;
	}
	while (stream->following)
	{
		if (strcmp(stream->following->passport, passport) == 0)
		{
			dummy = stream->following;
			stream->following = stream->following->following;
			free(dummy);
			printf("has been deleted ");
			getch();
			Sleep(800);
			return;
		}
		stream = stream->following;
	}
	printf("Passport number is wrong. Please check your passport");
}
