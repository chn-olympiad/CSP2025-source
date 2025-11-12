#include<cstdio>
char a[1000500];
int b[1000500],c;
int main()
{
	int i,j,k,sum=1,max=-1,max2=10,d;
    bool flag=true;
    FILE *in = fopen("number.in","r");
    FILE *out = fopen("number.out","w");
    fscanf(in,"%s",a);
    for(i=0,j=1;a[i]!='\0';i++)
    {
        if(a[i]<='9' && a[i]>='0')
        {
            b[j]=a[i]-'0';
            j++;
        }
    }
    d=j;
    for(i=1;i<=d;i++)
    {
        for(j=1;j<=d-1;j++)
        {
            if(b[j]<b[j+1])
            {
                c=b[j];
                b[j]=b[j+1];
                b[j+1]=c;
            }
        }
    }
    for(i=1;i<=d-1;i++)
    {
        fprintf(out,"%d",b[i]);
    }
    return 0;
}
