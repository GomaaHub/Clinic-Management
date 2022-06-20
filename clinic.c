#include <stdio.h>
#include <stdlib.h>
#define ZERO 0
#define NAME_LENGTH 15
#include "types.h"
#include "bit_math.h"
#include "check_functions.h"
#include "header_functions.h"
#include "linked_list.h"





void main(void)
{
	node *head;
	node1 *head1;
	
	
	u8 mode,admin,user,edit,h;
	u8 l=1;
	u8 trial=ZERO;
	u8 A;
	int age,new_age;
	u16 ID;
	u8 yn;
	u8 yn1;
	char name[NAME_LENGTH],new_name[NAME_LENGTH];
	char gender,new_gender;
	
	char slot1[20]="2:00PM -> 2:30PM";
	char slot2[20]="2:30PM -> 3:00PM";
	char slot3[20]="3:00PM -> 3:30PM";
	char slot4[20]="4:00PM -> 4:30PM";
	char slot5[20]="4:30PM -> 5:00PM";
	u8 slot1_num=1;
	u8 slot2_num=2;
	u8 slot3_num=3;
	u8 slot4_num=4;
	u8 slot5_num=5;
	
	STATUS pass_result;
	STATUS rtn;
	
	head=NULL;
	head1=NULL;

	printf("\nPlease choose the user mode: \n\n1. Admin\n2. User\n\nPlease enter your choice: ");
	scanf("%d",&mode);
	printf("\n");
	
	do
	{
	
	switch(mode)
	{
		case 1:
		{
			printf("Enter the password: ");
			pass_result=check_pass(&trial);
			if(pass_result==SUCCESS)
			{
		
			printf("You are now in admin mode!\n\n");
			
			do
			{
			printf("What would you like to do: \n\n");
			
			
			printf("1. Add a new patient\n2. Edit patient information\n3. Reserve a slot with the doctor\n4. Cancel reservation\n5. View Clinic database\n6. Exit\n\nPlease enter your choice: ");
			scanf("%d",&admin);
			switch(admin)
			{
				case 1:
				{
					printf("Please fill out the following information:\n\n");
					printf("Name: ");
					scanf("\n");
					scanf("%[^\n]%*c",name);
					
					printf("Age: ");
					scanf("%u",&age);
					
					printf("Gender (M for Male or F for Female): ");
					
					scanf("%s",&gender);
					
					
					printf("ID: ");
					scanf("%u",&ID);
					
					
					printf("\n");
					head=insert_beginning1(head,name,age,gender,ID);
					printf("\n");
					
					
					
					
					break;
				}
				case 2:
				{
					printf("Enter the patient ID: ");
					scanf("%u",&ID);
					A=check_ID(head,ID);
					if(A==1)
					{
					printf("What info would you like to edit?\n\n");
					printf("1. Name\n2. Age\n3. Gender\n\nEnter your choice: ");
					scanf("%u",&edit);
					switch(edit)
					{
						case 1:
						{
							printf("Enter the new name: ");
							scanf("\n");
							scanf("%[^\n]%*c",new_name);
							A=edit_name(head,new_name,ID);
							if(A==1)
							{
								printf("\nThe patient info has been successfully updated!\n\n");
							}
							else
							{
								printf("\n");
							}
							break;
						}
						case 2:
						{
							printf("Enter the new age: ");
							scanf("%u",&new_age);
							A=edit_age(head,new_age,ID);
							if(A==1)
							{
								printf("\nThe patient info has been successfully updated!\n\n");
							}
							else
							{
								printf("\n");
							}
							
							break;
						}
						case 3:
						{
							printf("Enter the new gender: ");
							scanf("%s",&new_gender);
							A=edit_gender(head,new_gender,ID);
							if(A==1)
							{
								printf("\nThe patient info has been successfully updated!\n\n");
							}
							else
							{
								printf("\n");
							}
							
							break;
						}
						default:
						{
							printf("Invalid Choice!\n\n");
							break;
						}
					}
					}
				
					else
					{
						printf("\n\nInvalid ID!\n\n");
					}
					
					
					break;
				}
				case 3:
				{
					printf("\n");
					printf("Enter the patient's ID: ");
					scanf("%u",&ID);
					printf("\n");
					A=check_ID(head,ID);
					
					if(A==1)
					{
					while(l==1)
					{
					head1=insert_slot_end(head1,slot1,slot1_num);
					head1=insert_slot_end(head1,slot2,slot2_num);
					head1=insert_slot_end(head1,slot3,slot3_num);
					head1=insert_slot_end(head1,slot4,slot4_num);
					head1=insert_slot_end(head1,slot5,slot5_num);
					l=0;
					};
					
				
					printf("The available slots are: \n\n");
					print_slots(head1);
					printf("\n");
					printf("Choose slot number: ");
					scanf("%u",&h);
					if(h>=1 && h<=5)
					{
					A=check_slot(head1,h);
					if(A==1)
					{
					assign_slot(head1,ID,h);
					printf("\nReservation successfully done!\n\n");
					}
					else
					{
						printf("\nSlot is already taken :(\n\n");
					}
					}
					else
					{
						printf("\nInvalid slot number :)\n\n");
					}
					}
					else
					{
						printf("Invalid ID!\n\n");
					}
					
					
					break;
				}
				case 4:
				{
					printf("\n      SLOT TIME          ID\n\n");
					print_schedule(head1);
					
					printf("\nEnter the patient's ID:  ");
					scanf("%u",&ID);
					A=check_ID(head,ID);
					if(A==1)
					{
					A=cancel_slot(head1,ID);
					if(A==1)
					{
						printf("\nReservation successfully canceled!\n\n");
					}
					else if (A==0)
					{
						printf("\nThe ID you entered does not have a reservation!\n\n");
					}
					else
					{
						printf("");
					}
					}
					else
					{
						printf("\nThe ID you entered is not registered in the system!\n\n");
					}
					break;
				}
				case 5:
				{
					printf("\nNAME            AGE  G   ID\n\n");
					print_list(head);
					break;
				}
				case 6:
				{
					
				}
				default:
				{
					printf("\nInvalid Choice!\n\n");
					break;
				}
			}
			printf("Would you like to do anything else as an Admin? Enter 1 for yes and 0 for no: ");
			scanf("%u",&yn);
			}while(yn==1);
			
			break;
			
			}	
			else
			{
				break;
			}
			
		
		}
	
		case 2:
		{
			do
			{
			printf("You are now in User mode!\n\nWhat would you like to do?\n\n");
			printf("1. View patient information\n2. View today's schedule\n3. Exit\n\nPlease Enter your choice: ");
			scanf("%u",&user);
			
			switch(user)
			{
				case 1:
				{	
					printf("Enter the patient's ID: ");
					scanf("%d",&ID);
					printf("\n");
					A=check_ID(head,ID);
					if(A==1)
					{
						printf("\nNAME            AGE  G\n\n");
						print_patient(head,ID);
					}
					else
					{
						printf("Invalid ID!\n\n");
					}
					break;
				}
				case 2:
				{
					printf("\n      SLOT TIME          ID\n\n");
					print_schedule(head1);
					break;
				}
				case 3:
				{
					break;
				}
				default:
				{
					printf("\nInvalid Choice!\n");
					break;
				}
			}
			printf("\nWould you like to do anything else as a User? Enter 1 for yes or 0 for no: ");
			scanf("%u",&yn1);
			}while(yn1==1);
			
			break;
		}
		
		default:
		{
			printf("Invalid Choice!\n");
			break;
		}
	}
	printf("\nContinue as Admin or User? Enter 1 for Admin mode or 2 for User mode: ");
	scanf("%u",&mode);
	}while(mode==1 || mode==2);
}


