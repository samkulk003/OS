#include <stdio.h>

void fcfs(int a[100],int head,int n)
{
    int finish[100],i;
    int min,diff,distance=0;
     printf("%d=>",head);
    for(i=0;i<n;i++)
    {
        printf("%d=>",a[i]);
        distance+=abs(head-a[i]);
    }
printf("\nend\n");
    printf("distance:\t%d",distance);

}

void sort(int a[100],int n)
{
    int i,j,temp;
    for (i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }

}
void ss(int a[100],int head,int n)
{
    int finish[100];
    int min,diff,i,pending=n,index,distance;
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    while(pending>0)
    {
      min=9999;
        for(i=0;i<n;i++)
        {
            diff=abs(head-a[i]);
            if(diff<min && finish[i]==0)
            {
                min=diff;
                index=i;
            }

        }
        finish[index]=1;
        pending--;
        distance+=abs(head-a[index]);
        head=a[index];

    }
    printf("\nend\n");
    printf("distance:\t%d",distance);

}

void scan(int a[100],int head,int n,int t)
{
    int finish[5];
    int min,diff,i,index=0,distance=0;
    for(i=0;i<5;i++)
    {
        finish[i]=0;
    }
    printf("\nsorted");
     sort(a,n);
     for(i=0;i<=n;i++)
    {
       printf("%d\t",a[i]);
    }

    printf("enter 1 for right and 2 for lrft");
    int dir;
    scanf("\n%d",&dir);

    for(i=0;i<n;i++)
    {
       if(a[i]<=head)
       index=i;
    }
    printf("%d=>",head);
    if(dir==1)
    {
        for(i=index+1;i<n;i++)
        {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;
        }
            printf("%d=>",t-1);
            distance+=abs(head-(t-1));
            head=t-1;
        for(i=index;i>=0;i--)
            {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;

            }


    }
    else
    {
         for(i=index;i>=0;i--)
        {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;
        }
            printf("%d=>",0);
            distance+=abs(head-0);
            head=0;
        for(i=index+1;i<n;i++)
            {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;

            }


    }
    printf("\nend\n");
    printf("distance:\t%d",distance);



}
void cscan(int a[100],int head,int n,int t)
{
    int finish[4];
    int min,diff,i,index=0,distance=0;
    for(i=0;i<4;i++)
    {
        finish[i]=0;
    }
    printf("\nsorted");
     sort(a,n);
     for(i=0;i<=n;i++)
    {
       printf("%d\t",a[i]);
    }

    printf("enter 1 for right and 2 for lrft");
    int dir;
    scanf("\n%d",&dir);

    for(i=0;i<n;i++)
    {
       if(a[i]<=head)
       index=i;
    }
    printf("%d=>",head);
    if(dir==1)
    {
        for(i=index+1;i<n;i++)
        {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;
        }
            printf("%d=>",t-1);
            distance+=abs(head-(t-1));
            head=t-1;
        for(i=index;i>=0;i--)
            {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;

            }
            printf("%d=>",0);
            distance+=abs(head-0);
            head=0;


    }
    else
    {
         for(i=index;i>=0;i--)
        {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;
        }
            printf("%d=>",0);
            distance+=abs(head-0);
            head=0;
        for(i=index+1;i<n;i++)
            {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;

            }
            printf("%d=>",t-1);
            distance+=abs(head-(t-1));
            head=t-1;


    }
    printf("\nend\n");
    printf("distance:\t%d",distance);




}
void look(int a[100],int head,int n,int t)
{
    int finish[5];
    int min,diff,i,index=0,distance=0;
    for(i=0;i<5;i++)
    {
        finish[i]=0;
    }
    printf("\nsorted");
     sort(a,n);
     for(i=0;i<=n;i++)
    {
       printf("%d\t",a[i]);
    }

    printf("enter 1 for right and 2 for lrft");
    int dir;
    scanf("\n%d",&dir);

    for(i=0;i<n;i++)
    {
       if(a[i]<=head)
       index=i;
    }
    printf("%d=>",head);
    if(dir==1)
    {
        for(i=index+1;i<n;i++)
        {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;
        }

        for(i=index;i>=0;i--)
            {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;

            }


    }
    else
    {
         for(i=index;i>=0;i--)
        {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;
        }

        for(i=index+1;i<n;i++)
            {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;

            }


    }
    printf("\nend\n");
    printf("distance:\t%d",distance);






}
void clook(int a[100],int head,int n,int t)
{
     int finish[4];
    int min,diff,i,index=0,distance=0;
    for(i=0;i<4;i++)
    {
        finish[i]=0;
    }
    printf("\nsorted");
     sort(a,n);
     for(i=0;i<=n;i++)
    {
       printf("%d\t",a[i]);
    }

    printf("enter 1 for right and 2 for lrft");
    int dir;
    scanf("\n%d",&dir);

    for(i=0;i<n;i++)
    {
       if(a[i]<=head)
       index=i;
    }
    printf("%d=>",head);
    if(dir==1)
    {
        for(i=index+1;i<n;i++)
        {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;
        }

        for(i=0;i<=index;i++)
            {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;

            }



    }
    else
    {
         for(i=index;i>=0;i--)
        {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;
        }

        for(i=n-1;i>index;i--)
            {
            printf("%d=>",a[i]);
            distance+=abs(head-a[i]);
            head=i;

            }



    }
    printf("\nend\n");
    printf("distance:\t%d",distance);






}

int main()
{
    int i,t,n,h,a[100];
    printf("\n enter total no");
    scanf("\n%d",&t);
    printf("\n enter no of req");
    scanf("\n%d",&n);
    printf("\n enter head");
    scanf("\n%d",&h);
    printf("\n enter requests");
    for(i=0;i<n;i++)
        {
            scanf("\n%d",&a[i]);
        }

    printf("\n 1:fcfs 2:ss 3:scan 4:cscan 5:look 6:clook");
    int s;
    scanf("\n%d",&s);
    switch(s)
    {
    case 1:
        fcfs(a,h,n);
        break;
    case 2:
        ss(a,h,n);
        break;
    case 3:
        scan(a,h,n,t);
        break;
    case 4:
        cscan(a,h,n,t);
        break;
    case 5:
        look(a,h,n,t);
        break;
    case 6:
        clook(a,h,n,t);
        break;
    default:
        printf("wrong choice");
        break;

    }

}

