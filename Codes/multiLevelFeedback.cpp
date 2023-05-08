#include<bits/stdc++.h>
using namespace std;
struct process
{
    char name;
    int PQ,BT,WT,TAT,RT,CT;
}Q1[10],Q2[10],Q3[10];//Three queues

int n;
void sortByProcessID(){
    struct process temp;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            {
                if(Q2[i].name>Q2[j].name)
                    {
                          temp=Q2[i];
                          Q2[i]=Q2[j];
                          Q2[j]=temp;
                    }
            }
    }
}
void sortByPriority()
{
struct process temp;
int i,j;
for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            {
                if(Q1[i].PQ<Q1[j].PQ)
                    {
                          temp=Q1[i];
                          Q1[i]=Q1[j];
                          Q1[j]=temp;
                    }
            }
    }
}

int main()
{
     int i,j,k=0,r=0,time=0,tq1=10, flag=0;
     char c;
     printf("Enter no of processes:");
     scanf("%d",&n);
     int tq2=16/n;
     int BTr[n];
     for(i=0,c='A';i<n;i++,c++)
     {
         Q1[i].name=c;
         printf("\nEnter the Priority and burst time of process %c: ",Q1[i].name);
         scanf("%d%d",&Q1[i].PQ,&Q1[i].BT);
         Q1[i].RT=Q1[i].BT;//save burst time in remaining time for each process/
         BTr[i] = Q1[i].BT;

    }
sortByPriority();
printf("Process in first queue following priority queue with t=10");
printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
for(i=0;i<n;i++)
{

  if(Q1[i].RT<=tq1)
  {

       time+=Q1[i].BT;//from arrival time of first process to completion of this process/
       Q1[i].TAT=time;  //amount of time to execute the process/
       Q1[i].RT=0;
       Q1[i].WT=time-Q1[i].BT;//amount of time process has been waiting in the first queue/
       tq1 -= time;
       printf("\n%c\t\t%d\t\t%d\t\t%d",Q1[i].name,Q1[i].BT,Q1[i].WT,Q1[i].TAT);
  }
      Q2[k].WT=time;
      time+=tq1;
      Q1[i].RT-=tq1;
      Q2[k].BT=Q1[i].RT;
      Q2[k].RT=Q2[k].BT;
      Q2[k].name=Q1[i].name;
      tq1 = 0;
      k=k+1;
      flag=1;
}
sortByProcessID();
if(flag==1)
 {printf("\nProcess in second queue following RR with qt=15");
  printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
}for(i=0;i<k;i++)
   {
    if(Q2[i].RT<=tq2)
     {
       time+=Q2[i].BT;//from arrival time of first process +BT of this process/
       Q2[i].RT=0;
       Q2[i].WT=time-Q2[i].BT;//amount of time process has been waiting in the ready queue/
       Q2[i].TAT=time;//amount of time to execute the process/
       printf("\n%c\t\t%d\t\t%d\t\t%d",Q2[i].name,Q2[i].BT,Q2[i].WT,Q2[i].TAT);

    }
    else//process moves to queue 3 with FCFS/
    {
      Q3[r].PQ=time;
      time+=tq2;
      Q2[i].RT-=tq2;
      Q3[r].BT=Q2[i].RT;
      Q3[r].RT=Q3[r].BT;
      Q3[r].name=Q2[i].name;
      r=r+1;
      flag=2;
    }
  }

{if(flag==2)
printf("\nProcess in third queue following FCFS ");
}
for(i=0;i<r;i++)
{
    if(i==0)
            Q3[i].CT=Q3[i].BT+time;
        else
            Q3[i].CT=Q3[i-1].CT+Q3[i].BT;

}

for(i=0;i<r;i++)
    {
        Q3[i].TAT=Q3[i].CT;
        Q3[i].WT=Q3[i].TAT-BTr[i];
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t",Q3[i].name,BTr[i],Q3[i].WT,Q3[i].TAT);

    }

}