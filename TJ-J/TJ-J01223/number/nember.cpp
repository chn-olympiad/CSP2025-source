#include <iostream>
using namesapce std;
int sum,a[1005],b;
char n;
int main()
{
    freget("nember.in","w"stdin);
    freget("nember.out","s",stdout);
    cin>>n;
    for(int i=1;i<=n.size();i++)
    {
        if(c[i]==1\\c[i]==2\\c[i]==3\\c[i]==4\\c[i]==5\\c[i]==6\\c[i]==7\\c[i]==8\\c[i]==9)
        {
            a[i]=c[i];
        }
    }
    for(int i=1;i<=n.size();i++)
    {
        if(a[i]<a[i+1])
        {
            b=a[i+1];
            a[i+1]=a[i];
            a[i]=b[i];
        }
    }
    for(int i=1;i<=n.size();i++)
    {
        cout<<a[i];
    }
}
