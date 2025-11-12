#include<iostream>
using namespace std;
string s;
long long a[10000005];
int main()
{
	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)
    int t;
	cin>>s;
	for(int i=1;i<=s.size();i++)
	{
		if(s.size()==1)
		{
			if(s=="1"||s=="2"||s=="3"||s=="4"||s=="5"||s=="6"||s=="7"||s=="8"||s=="9")
     		{
	     		cout<<s;
	     	}
		}
		if(s.size()>1)
		{
			if(s=="1"||s=="2"||s=="3"||s=="4"||s=="5"||s=="6"||s=="7"||s=="8"||s=="9")
     		{
     			a==s;
				for(int k=i;k<=s.size();k++)
				{
					if(a[k]>a[k+1])
					{
						swap(a[k],a[k+1])
					}
					cout<<a[k];
				}
	     	}
		}
	}
	return 0;
}
