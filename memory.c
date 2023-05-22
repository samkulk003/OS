#include <stdio.h>
void fifo(int f[3],int s[7],int n,int m)
{
    int i,j,check,hit=0,fault=0,hf[100],x,c=0,k=0;
    for(i=0;i<m;i++)
    {
        f[i]=0;
    }

    printf("\nstring\tf1\tf2\tf3\th/f");
    for(i=0;i<n;i++)
    {
        check=0,c=0;
        for(j=0;j<m;j++)
        {
            if(f[j]==s[i])
            {
                check=1;
                hf[i]=1;
                hit++;

            }

        }
            if(check==0)
            {
                f[k]=s[i];
                k=(k+1)%m;
                hf[i]=0;
                fault++;

                }
                printf("\n%d\t",s[i]);
        for(j=0;j<m;j++)
        {
            printf("%d\t",f[j]);
        }
         printf("%d\t",hf[i]);

            }



}

int lru_p(int time[],int m)
{
    int i,min,pos=0,j;

         min=time[0];
         for(j=0;j<m;j++)
         {
             if(time[j]<min)
             {
                 min=time[j];
                 pos=j;
             }
         }

     return pos;

}

void lru(int f[3],int s[7],int n,int m)
{
    int i,j,check,hit=0,fault=0,hf[100],x,c=0,k=0,count,time[100],flag1,flag2;

    for(i=0;i<m;i++)
    {
        f[i]=-1;
    }
    printf("\nstring\tf1\tf2\tf3\th/f");
    for(i=0;i<n;i++)
    {
        flag1=flag2=0;
        for(j=0;j<m;j++)
        {
            if(f[j]==s[i])
            {
                hit++;
                count++;
                hf[i]=1;
                time[j]=count;
                flag1=flag2=1;
                break;
            }
        }
        if(flag1==0)
        {
           for(j=0;j<m;j++)
           {

           if(f[j]==-1)
           {
            f[j]=s[i];
            fault++;
            count++;
            hf[i]=0;
            time[j]=count;
            flag2=1;
            break;
        }
           }
        }
        if(flag2==0)
        {
           int pos=lru_p(time,m);
           f[pos]=s[i];
           fault++;
            count++;
            hf[i]=0;
            time[pos]=count;

        }
        printf("\n%d\t",s[i]);
        for(j=0;j<m;j++)
        {
            printf("%d\t",f[j]);
        }
         printf("%d\t",hf[i]);

            }

    }



void optimal(int f[3],int s[7],int n,int m)
{
    int i,j,check,hit=0,fault=0,hf[100],x,c=0,k=0,count,time[100],flag1,flag2,flag3,temp[100],pos,max;

    for(i=0;i<m;i++)
    {
        f[i]=-1;
    }
    printf("\nstring\tf1\tf2\tf3\th/f");
    for(i=0;i<n;i++)
    {
        flag1=flag2=0;
        for(j=0;j<m;j++)
        {
            if(f[j]==s[i])
            {
                hit++;
                count++;
                hf[i]=1;
                time[j]=count;
                flag1=flag2=1;
                break;
            }
        }
        if(flag1==0)
        {
           for(j=0;j<m;j++)
           {

           if(f[j]==-1)
           {
            f[j]=s[i];
            fault++;
            count++;
            hf[i]=0;
            time[j]=count;
            flag2=1;
            break;
        }
           }
        }
        if(flag2==0)
        {
           for(j=0;j<m;j++)
           {
               temp[j]=-1;
               for(k=i+1;k<n;k++)
               {
                   flag3=0;
                   if(f[j]==s[k])
                   {
                      temp[j]=k;
                      break;
                   }
               }
           }
           for(j=0;j<m;j++)
           {
             if(temp[j]==-1)
             {
               pos=j;
               flag3=1;
               break;
             }

           }
           if(flag3==0)
           {
               max=temp[0];
               for(j=0;j<m;j++)
               {
                   if(temp[j]>max)
                   {
                       max=temp[j];
                       pos=j;
                   }
               }
           }
           fault++;
           f[pos]=s[i];
           hf[i]=0;



        }
        printf("\n%d\t",s[i]);
        for(j=0;j<m;j++)
        {
            printf("%d\t",f[j]);
        }
         printf("%d\t",hf[i]);

            }

}
  int lfu_p(int s[],int f[],int pos,int m)
{
    int i,j,freq[100],ind[100],index=pos,min=999,frind;
    for(i=0;i<m;i++)
    {        freq[i]=0;
               ind[i]=0;
        for(j=i;j>=0;j--)
        {
            if(s[j]=f[i])
            {
               freq[i]++;
               ind[i]=j;
            }
        }
        if(freq[i]<min && ind[i]<index)
        {
            min=freq[i];
            index=ind[i];
            frind=i;
        }
    }
    return frind;
}

void lfu(int f[3],int s[7],int n,int m)
{
        int i,j,check,hit=0,fault=0,hf[100],x,c=0,k=0,count,time[100],flag1,flag2;

    for(i=0;i<m;i++)
    {
        f[i]=-1;
    }
    printf("\nstring\tf1\tf2\tf3\th/f");
    for(i=0;i<n;i++)
    {
        flag1=flag2=0;
        for(j=0;j<m;j++)
        {
            if(f[j]==s[i])
            {
                hit++;
                count++;
                hf[i]=1;
                time[j]=count;
                flag1=flag2=1;
                break;
            }
        }
        if(flag1==0)
        {
           for(j=0;j<m;j++)
           {

           if(f[j]==-1)
           {
            f[j]=s[i];
            fault++;
            count++;
            hf[i]=0;
            time[j]=count;
            flag2=1;
            break;
        }
           }
        }
        if(flag2==0)
        {
           int pos=lfu_p(s,f,i,m);
           f[pos]=s[i];
           fault++;
            count++;
            hf[i]=0;
            time[pos]=count;

        }
        printf("\n%d\t",s[i]);
        for(j=0;j<m;j++)
        {
            printf("%d\t",f[j]);
        }
         printf("%d\t",hf[i]);

            }

}

int main()
{
    int f[3],s[5],n,m,i,j;
    printf("\nno of n frames");
    scanf("\n%d",&m);
     printf("\nno of n pages");
     scanf("\n%d",&n);
      printf("\nenetr pages or reff string");
      for(i=0;i<n;i++)
      {
          scanf("\n%d",&s[i]);
      }

      lfu(f,s,n,m);



}
