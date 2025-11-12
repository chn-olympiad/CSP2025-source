#include<bits/stdc++.h>
using namespace std;
string b;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string a;
    cin>>a;
	for(int i=1;i<=a.size();i++)
    {
        int c=0;
        int n=a[i];
        if(n<10)
        {
    		b[c]=n;
            c++;
        }
    }
	for(int i=1;i<=b.size();i++)
    {
    	int i1,i2;
    	char i3=b[i],i4=b[i+1];
    	i1=i3;
    	i2=i4;
    	if(i1<i2)
    	{
    		char e,f;
			e=b[i];
			f=b[i+1];
			b[i]=f;
			b[i+1]=e;
		}
    }
    for(int i=1;i<=100000;i++)
    {
    	cout<<b[i];
    }
	return 0;
}

