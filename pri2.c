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

void pri_pree(int pri[],int a[],int b[],int n,int rt[])
{
    int time,i,j,min,c[100],remain=n,preproc,smallest,index,ctr=1,gid[100],gp[100],tat,wt,ct;
    for(i=0;i<n;i++)
    {
        c[i]=0;
    }
    preproc=0;
    printf("\np\tAT\tBT\tCT\tTAT\tWT");
    for(time=0;remain!=0;time++)
    {
        min=100;
        smallest=5;
        for(i=0;i<n;i++)
        {
            if(a[i]<=time && pri[i]<min && rt[i]>0 )
            {
                min=pri[i];
                index=i;


            }
        }
        if(preproc!=index)
        {
            gid[ctr]=index+1;
            gp[ctr]=time+1;
            ctr++;

        }
        preproc=index;
        rt[index]--;
        if(rt[index]==0)
       {
        remain--;
        ct=time+1;
        tat=ct-a[index];
        wt=ct-a[index]-b[index];
        printf("\n%d\t%d\t%d\t%d\t%d\t%d",index+1,a[index],b[index],ct,tat,wt);
        if(remain==n)
            {
                gp[ctr]=time+1;
                ctr++;
            }





    }



}
gid[0]=0;
gp[0]=a[0];
printf("\n\n\n");
for(i=0;i<ctr;i++)
{
    printf("   p%d\t",gid[i]);
}
printf("\n");
for(i=0;i<ctr;i++)
{
    printf("%d\t",gp[i]);
}
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
    printf("enter priotity \n");
    for(i=0;i<n;i++)
    {
        printf("process %d\n",p[i]);
        scanf("%d",&pri[i]);
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
    pri_pree(pri,a,b,n,rt);


}






