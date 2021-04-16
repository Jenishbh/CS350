#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"
typedef struct item{
   int sales;
   float expenses;
   char lname[32],fname[32];
} ITEM;
int compare(ITEM* item1, ITEM* item2){

   ITEM *p = (ITEM*) item1;
   ITEM *q = (ITEM*) item2;
        int l = strlen(p->lname) < strlen(q->lname) ? strlen(p->lname) : strlen(q->lname);
   for(int i = 0 ; i < l ; i++ ){
       if( p->lname[i] < q->lname[i] )return -1;
       else if(p->lname[i] > q->lname[i])return 1;
   }
   return 0;

}
void display(void* item){
   ITEM *p = (ITEM*) item;
   printf("%10s %10s %20d %20.4f\n",p->fname,p->lname,p->sales,p->expenses);
   //printf("key = %d, name = %s\n", p->key, p->name);
}
int main(void) {
   ITEM* p;
   LIST* L = createList(compare);
   char file_Name[100];
   FILE *fptr,*fp;
        ITEM arr[1000];
   // insert 5 items
   printf("Enter name of a file to read : ");
   scanf("%[^\n]s",file_Name);
   fptr = fopen(file_Name, "r");
        int Len=0;
    if (fptr == NULL){
          perror("Error while opening the file.\n");
          exit(EXIT_FAILURE);
        }else{
       char buf[100];
       while(fscanf(fptr,"%s",buf)!=EOF){
              p = (ITEM*) malloc(sizeof(ITEM));
                      strcpy(p->lname,buf);
                  fscanf(fptr,"%s",buf);
              strcpy(p->fname,buf);
              fscanf(fptr,"%d",&p->sales);
                  fscanf(fptr,"%f",&p->expenses);
              arr[Len++]=*p;
       }
   }
   display(&arr[0]);
   displayList(L, display);
    qsort((void*)arr, Len, sizeof(arr[0]), compare);
   int Total_sale=0;
   float Total_expense = 0;
   for( int i = 0 ; i < Len ;i++)
       {insert(L,&arr[i]);Total_sale+=arr[i].sales;Total_expense+=arr[i].expenses;}
   printf("After reading input file , items....\n");
   displayList(L, display);getchar();
   printf("Enter name of a file to write : ");
   scanf("%[^\n]s",file_Name);
   fp = fopen(file_Name, "w");
   if (fp == NULL){
          perror("Error while opening the file.\n");
          exit(EXIT_FAILURE);
        }else{
   fprintf(fp,"Total sales = %d Total expenses = %f\n\n",Total_sale,Total_expense);
   fprintf(fp," Name of salesperson                   Sales(in %)   Expenses(in %)\n\n");
        for(int i = 0 ; i < Len ; i++ ){
       fprintf(fp,"%10s %10s %20.4f %20.4f\n",arr[i].fname,arr[i].lname,((float)arr[i].sales/(float)Total_sale)*100,(arr[i].expenses/Total_expense)*100);
   }
   }
   printf("\n\n");
return 0;
}