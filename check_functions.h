
u8 check_slot(node1 *head1,u8 slot_num)
{
	u8 g;
	node1 *temp;
	temp=head1;
	while (temp->slot_num!=slot_num)
	{
		temp=temp->next;
	}
	if(temp->ID==0)
	{
		g=1;
	}
	else
	{
		g=0;
	}
	return g;
}


u8 check_pass(u8 *trial)
{
	
	u8 result;
	u16 password;
	
	do
		{
			scanf("%d",&password);
			if((password==1234)||(*trial==2))
			{
				result=SUCCESS;
				break;
			}
			else
			{
			printf("Wrong password! You have %d more attempt(s). Please try again: ",2-*trial);
			(*trial)++;
			}
		}while(*trial<3);
		
		if((*trial==2)&&(password!=1234))
		{
			result=FAIL;
			printf("\nNo more attempts!\n");
			
		}
		else
		{
			result=SUCCESS;
			printf("\nYou have successfully logged in!\n\n");
		
		}
		*trial=0;
		return result;
}