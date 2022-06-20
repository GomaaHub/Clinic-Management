
u8 check_slot_ID(node1 *head1,u16 ID)
{
	u8 k;
	node1 *ptr;
	ptr=head1;
	
	if (head1==NULL)
	{
		k=0;
	}
	else
	{
		
	while(ptr->ID!=ID && ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	
	if(ptr->ID==ID)
	{
		k=1;
	}
	else
	{
		k=0;
	}
	
	}
	return k;
}


void print_patient(node *head,u16 ID)
{
	u8 i,k,j;
	node *temp;
	temp=head;
	
	while(temp->ID!=ID)
	{
		temp=temp->next;
	}
	
	for(i=ZERO;temp->name[i]!='\0';i++)
	{
		printf("%c",temp->name[i]);
		k++;
	}
		for(j=k;j<NAME_LENGTH;j++)
		{
			printf(" ");
		}
		if((temp->age>10) && (temp->age<100))
		{
		printf(" %d ",temp->age);
		}
		else if(temp->age>100)
		{
			printf(" %d",temp->age);
		}
		else
		{
			printf(" %d  ",temp->age);
		}
		
	
		printf("  %c ",temp->gender);
		
		printf("\n");
	
}

void print_schedule(node1 *head1)
{
	node1 *temp = head1;
	u8 i,k,j;
	
	
	while(temp!=NULL)
	{
		if(temp->ID!=0)
		{
		printf("%d) ",temp->slot_num);
		
		for(i=ZERO;i<20;i++)
	{
		printf("%c",temp->slot[i]);
	}
		printf("  %d",temp->ID);
		temp=temp->next;
		printf("\n");
		}
		else
		{
			temp=temp->next;
		}
	}
}

u8 cancel_slot(node1 *head1,u16 ID)
{
	u8 f,y;
	node1 *temp;
	temp=head1;
	
	y=check_slot_ID(head1,ID);
	if(y==1)
	{
	while(temp->ID!=ID)
	{
		temp=temp->next;
	}
	if(temp->ID==ID)
	{
		temp->ID=0;
		f=1;
	}
	else
	{
		f=0;
	}
	}
	else
	{
		f=0;
	}	
	return f;
}


void assign_slot(node1 *head1,u16 ID,u8 h)
{
	node1 *temp;
	temp=head1;
	
	while(temp->slot_num!=h)
	{
		temp=temp->next;
	}
	temp->ID=ID;
	
}


node1* insert_slot_start (node1 *head1, char *slot1,u8 slot_num)
{
	u8 i;
	
	node1 *temp,*ptr;
	
	temp=head1;
	ptr=head1;
	
	
	temp=(node1*)malloc(sizeof(node1));
	
	for(i=ZERO;i<20;i++)
	{
	temp->slot[i]=*slot1;
	slot1++;
	}
	temp->slot_num=slot_num;
	temp->ID=0;
	
	temp->next=head1;
	head1=temp;
	
	return head1;
}

node1* insert_slot_end (node1 *head1,char *slot1,u8 slot_num)
{
	
	node1 *temp,*ptr;
	u8 i;
	temp=head1;
	
	if(head1==NULL)
	{
		head1=insert_slot_start(head1,slot1,slot_num);
	}
	
	else
	{
	ptr=head1;
	temp=(node1*)malloc(sizeof(node1));
	
	for(i=ZERO;i<20;i++)
	{
	temp->slot[i]=*slot1;
	slot1++;
	}
	temp->slot_num=slot_num;
	temp->ID=0;
	temp->next=NULL;
	
	while((ptr->next)!= NULL)
	{
		ptr=ptr->next;
	}
	
	ptr->next=temp;
	
	
	}
	return head1;
	
}

void print_slots (node1 *head1)
{
	node1 *temp = head1;
	u8 i,k,j;
	
	
	while(temp!=NULL)
	{
		if(temp->ID==0)
		{
		printf("%d) ",temp->slot_num);
		
		for(i=ZERO;i<20;i++)
	{
		printf("%c",temp->slot[i]);
	}
		printf("  %d",temp->ID);
		temp=temp->next;
		printf("\n");
		}
		else
		{
			temp=temp->next;
		}
	}
	
	
}


u8 edit_age(node *head,u16 new_age,u16 ID)
{
	node *ptr;
	ptr=head;
	
	while(ptr->ID!=ID)
	{
		ptr=ptr->next;
	}
	ptr->age=new_age;
	
	return 1;
}

u8 edit_name(node *head,char *new_name,u16 ID)
{
	node *temp;
	temp=head;
	u8 i,j;
	
	while(temp->ID!=ID)
	{
		temp=temp->next;
	}
	for(i=ZERO;*new_name!='\0';i++)
	{
		temp->name[i]=*new_name;
		new_name++;	
	}
	
	for(j=i;j<15;j++)
	{
		temp->name[j]='\0';
	}
	
	return 1;
}

u8 edit_gender(node *head,char new_gender,u16 ID)
{
	node *ptr;
	ptr=head;
	
	while(ptr->ID!=ID)
	{
		ptr=ptr->next;
	}
	ptr->gender=new_gender;
	
	return 1;
}



u8 check_ID(node *head,u16 ID)
{
	u8 k;
	node *ptr;
	ptr=head;
	
	if (head==NULL)
	{
		k=0;
	}
	else
	{
		
	while(ptr->ID!=ID && ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	
	if(ptr->ID==ID)
	{
		k=1;
	}
	else
	{
		k=0;
	}
	
	}
	return k;
}


node* insert_beginning1 (node *head,char *name,int age,char gender, u16 ID)
{
	u8 i,j,k;
	
	k=check_ID(head,ID);
	
	if(k==0)
	{
		
	node *temp = (node*)malloc(sizeof(node));
	
	
	for(i=ZERO;*name!='\0';i++)
	{
		temp->name[i]=*name;
		name++;
	}
	for(j=i;j<15;j++)
	{
		temp->name[j]='\0';
	}
	
	temp->age=age;
	
	temp->gender=gender;
	temp->ID=ID;
	
	temp->next=head;
	head=temp;	
	printf("Patient successfully added!\n");
	}
	else
	{
		printf("ID already exists!\n");
	}
	
	return head;
}




void print_list (node *head)
{
	node *temp = head;
	u8 i,k,j;
	
	
	while(temp!=NULL)
	{
		k=0;
		for(i=ZERO;temp->name[i]!='\0';i++)
	{
		printf("%c",temp->name[i]);
		k++;
	}
		for(j=k;j<NAME_LENGTH;j++)
		{
			printf(" ");
		}
		if((temp->age>10) && (temp->age<100))
		{
		printf(" %d ",temp->age);
		}
		else if(temp->age>100)
		{
			printf(" %d",temp->age);
		}
		else
		{
			printf(" %d  ",temp->age);
		}
		printf("  %c ",temp->gender);
		
	
		printf("  %d  ",temp->ID);
		printf("\n");
		temp=temp->next;
	}
	
	printf("\n");
}

/*node* insert_end (node *head,char *name0,int age,char *gender0, int ID)
{
	
	node *temp,*ptr;
	temp=head;
	
	if(head==NULL)
	{
		head=insert_beginning(head,name,age,gender,ID);
	}
	
	else
	{
	ptr=head;
	temp=(node*)malloc(sizeof(node));
	
	temp->name[1]=*name;
	temp->age=age;
	temp->gender[1]=*gender;
	temp->ID=ID;
	
	temp->next=NULL;
	
	while((ptr->next)!= NULL)
	{
		ptr=ptr->next;
	}
	
	ptr->next=temp;
	
	
	}
	return head;
	
}*/

/*node* delete_node(node *head,u8 x)
{
	u8 k;
	node *ptr1=head;
	node *ptr2=head;
	
	if(head==NULL)
	{
		printf("The list is empty!\n");
	}
	else if(x==1)
	{
		head=ptr1->next;
		free(ptr1);
		ptr1=NULL;
		
		
	}
	else
	{
		while(x!=1 && ptr2->next!=NULL)
		{
			ptr2=ptr1;
			ptr1=ptr1->next;
			x--;
			k++;
		}
		if(ptr2->next==NULL)
		{
			printf("The position you entered is outside the list!\n");
		}
		else
		{
		ptr2->next = ptr1->next;
		free(ptr1);
		ptr1=NULL;
		}
		
	}
	return head;
}

node* delete_data(node *head,u8 x)
{
	u8 i;
	
	node *ptr1=head;
	node *ptr2=head;
	
	
	if(head==NULL)
	{
		printf("The list is empty!\n\n");
	}
	else if(head->data==x)
	{
		head=ptr1->next;
		free(ptr1);
		ptr1=NULL;
	}
	else
	{
		while(ptr1->data!=x && ptr1->next!=NULL)
		{
			ptr2=ptr1;
			ptr1=ptr1->next;
		}
		
		if(ptr1->next==NULL && ptr1->data!=x)
		{
			printf("The data you entered is not in the list!\n\n");
		}
		else
		{
		ptr2->next = ptr1->next;
		free(ptr1);
		ptr1=NULL;
		}
	}
	
	return head;
}*/

/*node* insert_at_n(node *head,u8 x,u8 y)
{
	u8 status;
	node *ptr,*ptr1;
	ptr=head;
	ptr1=(node*)malloc(sizeof(node));
	
	ptr1->data=x;
	ptr1->next=NULL;
	
	if(y==1)
	{
		ptr1->next=ptr;
		head=ptr1;
		
		status=TRUE;
	}
	else
	{
		while(y!=2 && ptr->next!=NULL)
		{
			ptr=ptr->next;
			y--;
		}
	
		if(ptr->next==NULL)
		{
			printf("The position you entered is outside the list!\n");
		}
		else
		{
	
			ptr1->next=ptr->next;
			ptr->next=ptr1;
			status=TRUE;
		}
	}
	return head;
}
*/
/*node* delete_last(node *head)
{
	if(head==NULL)
	{
		printf("There are no data in the list!\n");
	}
	else if(head->next==NULL)
	{
		free(head);
		head=NULL;
	}
	else
	{
		node *ptr1,*ptr2;
		ptr1=head;
		ptr2=head;
		while(ptr1->next!=NULL)
		{
			ptr2=ptr1;
			ptr1=ptr1->next;
		}
		ptr2->next=NULL;
		free(ptr1);
		ptr1=NULL;
		
	}
	return head;
}*/




