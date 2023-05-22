#include <stdio.h>
#include <conio.h>
void avg(int tat[],int wt[],int n)
{
    int stat=0,swt=0,i,atat,awt;
    for(i=0;i<n;i++)
    {
        stat=stat+tat[i];
        swt=swt+wt[i];
    }
    atat=stat/n;
    awt=swt/n;
    printf("%d %d",atat,awt);
}

void fcfs(int a[],int b[],int p[],int n,int ct[],int tat[],int wt[])
{
    int i,j,temp,x,s=0,y;
    printf("p  AT  BT  CT  TAT  WT\n");
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                x=p[i];
                p[i]=p[j];
                p[j]=x;
                y=b[i];
                b[i]=b[j];
                b[j]=y;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        s=s+b[i];
        ct[i]=s;
        tat[i]=ct[i]-a[i];
        wt[i]=tat[i]-b[i];
    }
    for(i=0;i<n;i++)
    {
         printf("%d  %d  %d  %d  %d  %d\n",p[i],a[i],b[i],ct[i],tat[i],wt[i]);

    }

    for(i=0;i<n;i++)
    {
      printf("| %d |",p[i]);

    }
    printf("\n");
    printf("%d",a[0]);
    for(i=0;i<n;i++)
    {
      printf("   %d",ct[i]);

    }
    printf("\n");

}

int main()
{
    int n,i,a[100],b[100],p[100],temp,j,x,ct[100],tat[100],wt[100];
    printf("enter no of processes\n");
    scanf("%d",&n);
     for(i=0;i<n;i++)
    {
        p[i]=i+1;
    }
    printf("enter arival time \n");
    for(i=0;i<n;i++)
    {
        printf("process %d\n",p[i]);
        scanf("%d",&a[i]);
    }
    printf("enter burst time\n");
    for(i=0;i<n;i++)
    {
        printf(" process 1 \n");
        scanf("%d",&b[i]);
    }
    printf("fcfs\n");
    fcfs(a,b,p,n,ct,tat,wt);
    avg(tat,wt,n);





}
