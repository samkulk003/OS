#include <stdio.h>
#include <conio.h>

void sjf(int a[],int b[],int n,int rt[])
{
    int preproc=0,gid[5],gp[5],ctr=1;
    printf("\np\t|\tCT\t|\tTAT\t|\tWT");
    int smallest,time,i,remain=0,ct,tat,wt;
    for(time=0;remain!=n;time++)
    {
        smallest=5;
        for(i=0;i<n;i++)
        {
            if(a[i]<=time && rt[i]>0 && rt[i]<=b[smallest])
            {

                smallest=i;
            }
        }
      if(smallest!=preproc)
      {
          gid[ctr]=smallest+1;
          gp[ctr]=time+1;
          ctr++;
      }
      preproc=smallest;

        rt[smallest]--;
        if(rt[smallest]==0)
        {
            remain++;
            ct=time+1;
            tat=ct-a[smallest];
            wt=ct-a[smallest]-b[smallest];
            printf("\np%d\t|\t%d\t|\t%d\t|\t%d",smallest+1,ct,tat,wt);
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
    int n,i,a[100],b[100],p[100],temp,j,x,ct[100],tat[100],wt[100],rt[100];

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
        rt[i]=b[i];
    }
    b[5]=999;


    printf("sjf\n");
    sjf(a,b,n,rt);





}
