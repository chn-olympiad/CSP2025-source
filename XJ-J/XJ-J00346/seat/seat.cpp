#include<cstdio>
int main()
{
    int n,m,i,j,a[500],b,c,d;
    scanf("%d %d",&n,&m);
    FILE *in = fopen("seat.in","r");
    FILE *out = fopen("seat.out","w");
    for(i=1;i<=n*m;i++)
    {
        fscanf(in,"%d",&a[i]);
    }
    b=a[1];
    for(i=1;i<=n*m;i++)
    {
        for(j=1;j<=n*m-1;j++)
        {
            if(a[j]<a[j+1])
            {
                c=a[j];
                a[j]=a[j+1];
                a[j+1]=c;
            }
        }
    }
    for(i=1;i<=n*m;i++)
    {
        if(a[i]==b)
        {
            break;
        }
    }
    d=i/m;
    if(d%2==1)
    {
        if(i==d*m)
        {
            fprintf(out,"%d %d",d,n);
        }
        else
        {
            fprintf(out,"%d %d",d+1,n-i+(d*m)+1);
        }
    }
    else
    {
        if(i==d*m)
        {
            fprintf(out,"%d %d",d,1);
        }
        else
        {
            fprintf(out,"%d %d",d+1,i-(d*m));
        }
    }
    return 0;
}
