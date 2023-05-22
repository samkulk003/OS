#include <stdio.h>
#include <conio.h>

void readmatrix(int a[100][100],int n,int m)
{

    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
         printf("\n");
    }
}
void printmatrix(int a[100][100],int n,int m)
{
     int i,j;

      for(i=0;i<n;i++)
    {
        printf("\n p%d\t",i);
        for(j=0;j<m;j++)
        {
            printf("%d",a[i][j]);
        }
         printf("\n");
    }

}

void cal_need(int alloc[100][100],int max[100][100],int m,int n)
{
     int i,j,need[100][100];

      for(i=0;i<n;i++)
    {
        printf("\n p%d\t",i);
        for(j=0;j<m;j++)
        {
           need[i][j]=max[i][j]-alloc[i][j] ;
        }
         printf("\n");
    }


}

void bankers(int need[100][100],int av[100],int alloc[100][100],int n,int m)
{
    int c[100],i,j,flag,k=0,ss[100];
    for (i=0;i<n;i++)
    {
        c[i]=0;
    }
    for(i=0;i<n;i++)
    {
        flag=0;
        if(c[i]==0){

        for(j=0;j<m;j++)
            {
               if(need[i][j]>av[j])
               {
                   flag=1;
                    break;

               }

            }
            if(flag==0)
            {
                c[i]=1;
                ss[k]=i;
                k++;
                for(j=0;j<m;j++){
                    av[j]=av[j]+alloc[i][j];}
                i=-1;
            }


        }
    }
    flag=0;
for(i=0;i<n;i++)
{
    if(c[i]==0)
    {
        printf("\ndeadlock\n");
        flag=1;
        break;
    }
}
if(flag==0)
{
    printf("\nsafe state\n");
    for(i=0;i<k;i++)
    {
        printf("p%d\t",ss[i]);
    }
}

}




int main()
{
    int n,m,alloc[100][100],max[100][100],av[100];
    printf("enter no of process and resourses");
    scanf("\n%d%d",&n,&m);
     printf("\nenetr allocation of all processes\n");
     readmatrix(alloc,n,m);
     printf("\nallocation\n");
     printmatrix(alloc,n,m);
     printf("\nenetr max of all processes");
     readmatrix(max,n,m);
     printf("\nmax\n");
     printmatrix(alloc,n,m);
      printf("\navailable\n");
      for(int i=0;i<m;i++){
     scanf("%d",&av[i]);}
     for(int i=0;i<m;i++){
     printf("%d",av[i]);}
     printf("\nneed\n");
     int need[100][100];

      for(int i=0;i<n;i++)
    {

        for(int j=0;j<m;j++)
        {
           need[i][j]=max[i][j]-alloc[i][j] ;
        }
         printf("\n");
    }
     printmatrix(need,n,m);

     bankers(need,av,alloc,n,m);


}

