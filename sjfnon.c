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

void sjf_non(int a[],int b[],int p[],int n)
{
    int time,i,j,min,c[100],remain=n,index=0,ctr=1,gid[100],gp[100],wt=0,tat=0,ct=0;
    for(i=0;i<n;i++)
    {
        c[i]=0;
    }
    printf("\np\tAT\tBT\tCT\tTAT\tWT");
    for(time=0;remain!=0;time++)
    {
        min=5;
        for(i=0;i<n;i++)
        {
            if(a[i]<=time && b[i]<b[min] && b[i]>0)
            {
                min=i;
                index=i;

            }
        }

        remain--;
        ct=ct+b[index];
        gid[ctr]=index;
        gp[ctr]=ct;
        ctr++;
        tat=ct-a[index];
        wt=ct-a[index]-b[index];
        printf("\n%d\t%d\t%d\t%d\t%d\t%d",index+1,a[index],b[index],ct,tat,wt);
        b[index]=0;






    }


gid[0]=0;
gp[0]=a[0];
    printf("\ngantt");
        printf("\n");
        for(i=0;i<ctr;i++)
        printf(" p%d",gid[i]+1);
         printf("\n");
         for(i=0;i<ctr;i++)
        printf("%d ",gp[i]);

}


int main()
{
    int n,i,a[100],b[100],p[100],pri[100],temp,j,x,rt[100];
    printf("enter no of processes\n");
    scanf("%d",&n);
     for(i=0;i<n;i++)
    {
        p[i]=i+1;
    }
    printf("enter arrival \n");
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
        rt[i]=b[i];
    }
    b[5]=999;
    printf("pri_non\n");
    sjf_non(a,b,p,n);


}





