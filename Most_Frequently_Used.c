#include<stdio.h>
#include<conio.h>
struct node
{
  int pno,freq;
}

frames[20];
int n;

int page_found(int pno)
{
  int fno;
  for(fno=0;fno<n;fno++)
    if(frames[fno].pno==pno)
       return fno;
    return -1;
}

int get_free_frame()
{  int fno;
  for (fno=0; fno<=n; fno++)
    if (frames[fno].pno==-1)
        return(fno);
   return(-1);
}

int get_mfu_frame()
{
  int fno;
  int selfno=0;
  for (fno=1; fno<n; fno++)
    if(frames[fno].freq>frames[selfno].freq)
    selfno=fno;
  return selfno;
}
void main()
{
   int p_request[50],z,k, hits = 0;
   printf("Enter Number of pages: ");
   scanf("%d",&z);
   for(k = 0; k < z; k++)
   {
   		printf("Enter Value No.[%d]:\t", k + 1);
        scanf("%d", &p_request[k]);
   }
   int size=z;
   int page_falts=0,i,j,fno;
   //clrscr();
   printf("\nHow many frames: ");  
   scanf("%d",&n);
   //initialize frames
   for (i=0; i<n; i++)
   { frames[i].pno=-1;
     frames[i].freq=0;
   }

   printf("\nPageNo     Page Frames       Page Fault");
   printf("\n------------------------------------------------");
   for(i=0;i<size;i++)
   {
     j=page_found(p_request[i]);
     if(j==-1)  //page fault occurs
     {
       j=get_free_frame();
       if (j==-1) //no free frame - do page replacement
         j=get_mfu_frame();
       page_falts++;
       frames[j].pno=p_request[i];
       frames[j].freq=1;
       printf("\n%4d\t ",p_request[i]);
       for (fno=0; fno<n; fno++)
	   {
       	 if(frames[fno].pno == -1)
       	 {
       	 	printf("");
			}
		else 
         printf("%4d",frames[fno].pno);
		 }
		 if(i==0)
       printf("\t\t\tYES");
       else
       printf("\t\tYES");
     }
    else //page found in frame j
    {
       printf("\n%4d\t ",p_request[i]);
       frames[j].freq++;
       for (fno=0; fno<n; fno++)
        {
       	 if(frames[fno].pno == -1)
       	 {
       	 	printf("");
			}
		else 
         printf("%4d",frames[fno].pno);
		 }
       printf("\t\tNO");
    }
   }
  printf("\n------------------------------------------------");
  hits = size - page_falts;
  printf("\n Number of Page Faults= %d",page_falts);
  printf("\n Number of Page Hits= %d",hits);
  getch();
}
