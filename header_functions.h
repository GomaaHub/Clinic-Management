
u8 edit_name(node *head,char *new_name,u16 ID);
u8 edit_gender(node *head,char new_gender,u16 ID);
u8 edit_age(node *head,u16 new_age,u16 ID);
node* insert_beginning1 (node *head,char *name,int age,char gender, u16 ID);
void print_list (node *head);
node* insert_end (node *head,char *name,int age,char gender, int ID);
node* delete_node(node *head,u8 x);
node* delete_data(node *head,u8 x);
node* insert_at_n(node *head,u8 x,u8 y);
node* delete_last(node *head);
u8 check_pass(u8 *trial);
u8 check_ID(node *head,u16 ID);
u8 cancel_slot(node1 *head1,u16 ID);
void print_patient(node *head,u16 ID);
void print_schedule(node1 *head1);
u8 check_slot(node1 *head1,u8 slot_num);

void print_slots (node1 *head1);
node1* insert_slot_start (node1 *head1,char *slot1,u8 slot_num);
node1* insert_slot_end (node1 *head1,char *slot1,u8 slot_num);
void assign_slot(node1 *head1,u16 ID,u8 h);
u8 check_slot_ID(node1 *head1,u16 ID);