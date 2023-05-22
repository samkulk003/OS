#include <stdio.h>
void first_fit(int p_size[3],int b_size[3],int n,int m)
{
    int alloc[100],i,j;
    for(i=0;i<n;i++)
    {
        alloc[i]=-1;
    }
    int index=0;
    for(i=0;i<n;i++)
    {
        for(j=index;j<m;j++)
        {
            if(b_size[j]>=p_size[i])
            {
                alloc[i]=j;
                index=j;
                b_size[j]=b_size[j]-p_size[i];
                break;
            }
        }

    }
    printf("\np\tps\tbno");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d",i+1,p_size[i]);
        if(alloc[i]!=-1)
        {
            printf("\t%d",alloc[i]+1);
        }
        else
        {
           printf("\tnot allocated");
        }



    }

}
void best_fit(int p_size[3],int b_size[3],int n,int m)
{
    int alloc[100],i,j,min,diff,index;
    for(i=0;i<n;i++)
    {
        alloc[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        min=9999;
        for(j=0;j<m;j++)
        {
            if(b_size[j]>=p_size[i])
            {
                diff=b_size[j]-p_size[i];
                if(diff<min)
                {
                    min=diff;
                    index=j;
                }

            }
        }
        alloc[i]=index;
                b_size[index]=b_size[index]-p_size[i];


    }
    printf("\np\tps\tbno");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d",i+1,p_size[i]);
        if(alloc[i]!=-1)
        {
            printf("\t%d",alloc[i]+1);
        }
        else
        {
           printf("\tnot allocated");
        }



    }


}
void worst_fit(int p_size[3],int b_size[3],int n,int m)
{
     int alloc[100],i,j,min,diff,index,temp;
    for(i=0;i<n;i++)
    {
        alloc[i]=-1;
    }
    for(i=0;i<m;i++)
    {
       for(j=i+1;j<m;j++)
       {
           if(b_size[j]>b_size[i])
           {
               temp=b_size[j];
               b_size[j]=b_size[i];
               b_size[i]=temp;
           }

       }
    }

    for(i=0;i<n;i++)
    {
        alloc[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(b_size[j]>=p_size[i])
            {
                alloc[i]=j;
                b_size[j]=b_size[j]-p_size[i];
                break;
            }
        }

    }
    printf("\np\tps\tbno");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d",i+1,p_size[i]);
        if(alloc[i]!=-1)
        {
            printf("\t%d",n-alloc[i]);
        }
        else
        {
           printf("\tnot allocated");
        }



    }



}

int main()
{
    int n,i,j,p_size[3],b_size[3];
    printf("\nenetr no of processes");
    scanf("\n%d",&n);
    printf("\nenetr  processes size");
    for(i=0;i<n;i++)
    {
       scanf("\n%d",&p_size[i]);
    }
    printf("\nenetr  block size");
    for(i=0;i<n;i++)
    {
       scanf("\n%d",&b_size[i]);
    }
    printf("\n enter 1 2 3 for first best worst");
    int s;
    int m =sizeof(b_size)/sizeof(b_size[0]);
    scanf("\n%d",&s);
    switch(s)
    {
    case 1:
        first_fit(p_size,b_size,n,m);
        break;
    case 2:
        best_fit(p_size,b_size,n,m);
        break;
    case 3:
        worst_fit(p_size,b_size,n,m);
        break;

    default:
        printf("wrong choice");
        break;

    }

}
