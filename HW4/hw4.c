#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node{
int coefficient;
int pow;
struct node *link;
};
struct node *mypol1=NULL,*my_pol2=NULL,*poly=NULL;
void create_node(struct node *node)
{
char ch;
do
{
printf("\n->Enter coefficient:");
scanf("%d",&node->coefficient);
printf("\n->Enter power:");
scanf("%d",&node->pow);
node->link=(struct node*)malloc(sizeof(struct node));
node=node->link;
node->link=NULL;
printf("\n continue(y/n):");
ch=getch();
}
while(ch=='y' || ch=='Y');
}
void show(struct node *node)
{
while(node->link!=NULL)
{
printf("%dx^%d",node->coefficient,node->pow);
node=node->link;
if(node->link!=NULL){
if(node->coefficient>0){
printf("+");
}
}
}
}
void Add_sub(struct node *mypol1,struct node *my_pol2,struct node *poly)
{
while(mypol1->link && my_pol2->link)
{
if(mypol1->pow>my_pol2->pow)
{
poly->pow=mypol1->pow;
poly->coefficient=mypol1->coefficient;
mypol1=mypol1->link;
}
else if(mypol1->pow<my_pol2->pow)
{
poly->pow=my_pol2->pow;
poly->coefficient=my_pol2->coefficient;
my_pol2=my_pol2->link;
}
else
{
poly->pow=mypol1->pow;
poly->coefficient=mypol1->coefficient+my_pol2->coefficient;
mypol1=mypol1->link;
my_pol2=my_pol2->link;
}
poly->link=(struct node *)malloc(sizeof(struct node));
poly=poly->link;
poly->link=NULL;
}
while(mypol1->link || my_pol2->link)
{
if(mypol1->link)
{
poly->pow=mypol1->pow;
poly->coefficient=mypol1->coefficient;
mypol1=mypol1->link;
}
if(my_pol2->link)
{
poly->pow=my_pol2->pow;
poly->coefficient=my_pol2->coefficient;
my_pol2=my_pol2->link;
}
poly->link=(struct node *)malloc(sizeof(struct node));
poly=poly->link;
poly->link=NULL;
}
}
main()
{
char ch;
do{
mypol1=(struct node *)malloc(sizeof(struct node));
my_pol2=(struct node *)malloc(sizeof(struct node));
poly=(struct node *)malloc(sizeof(struct node));
printf("\nEnter 1st polynomial: ");
create_node(mypol1);
printf("\nEnter 2nd polynomial: ");
create_node(my_pol2);
printf("\n1st polynomial: ");
show(mypol1);
printf("\n2nd polynomial: ");
show(my_pol2);
Add_sub(mypol1,my_pol2,poly);
printf("\nAdded polynomial: ");
show(poly);
printf("\nAdd two more numbers: ");
ch=getch();
}
while(ch=='y' || ch=='Y');
}