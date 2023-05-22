#include <stdio.h>
#include <conio.h>


void rr(int a[],int b[],int tq,int n,int ct[],int tat[],int wt[],int rt[])
{
    int i,j,temp,t,flag,stat=0,swt,avg_wt,avg_tat=0,y=n,gid[5],gp[5],ctr=0;
    gid[0]=0;
    gp[0]=0;


     printf("\np\tBT\tTAT\tWT");
    for(t=0,i=0;y!=0;)
    {
        if(rt[i]>0 && rt[i]<=tq)
        {
            t+=rt[i];
            gid[ctr]=i;
            gp[ctr]=t;
            rt[i]=0;
            flag=1;
            ctr++;
        }
        else if(rt[i]>0)
        {
            rt[i]-=tq;
            t=t+tq;
            gid[ctr]=i;
            gp[ctr]=t;

            ctr++;

        }

        if(rt[i]==0 && flag==1)
        {
            y--;
            printf("\n%d\t%d\t%d\t%d",i+1,b[i],t-a[i],t-a[i]-b[i]);
            swt=swt+t-a[i]-b[i];
            stat=stat+t-a[i];
            flag=0;
        }
        if(i==n-1)
        {
            i=0;
        }
        else if(a[i+1]<t)
        {
            i++;
        }
        else
        {
            i=0;
        }
    }
    avg_wt=swt/n;
    avg_tat=stat/n;
    printf("\n\n %d  %d",avg_tat,avg_wt);
    printf("\n");

    printf("\n\n");
     printf("\ngantt");
     printf("\n\n");
for(i=0;i<ctr;i++)
{
    printf("p%d\t",gid[i]+1);
}
printf("\n");
for(i=0;i<ctr;i++)
{
    printf("%d\t",gp[i]);
}

}





int main()
{
    int n,i,a[5],b[5],p[5],temp,t,tq,j,x,ct[5],tat[5],wt[5],rt[5];
    printf("enter no of processes\n");
    scanf("%d",&n);

    printf("enter arival time \n");
    for(i=0;i<n;i++)
    {
        printf("process %d\n",i+1);
        scanf("%d",&a[i]);
    }

    printf("enter burst time\n");
    for(i=0;i<n;i++)
    {
        printf(" process 1 \n");
        scanf("%d",&b[i]);
        rt[i]=b[i];
    }
        printf(" time quantum");
        scanf("%d",&tq);

    printf("rr\n");
    rr(a,b,tq,n,ct,tat,wt,rt);




}
