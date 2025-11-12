#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5;
int n,q;
string t1,t2,s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int i,j;
	cin>>n>>q;
	for(i=0;i<=n-1;i++)
	{
		cin>>s1>>s2[i];
	}
	int m=-1;
	while(q--)
	{
		cin>>t1>>t2;
		int sum=1e6;
		int strlen1=int('z');
		int strlen2=int('a');
		sum+=strlen1;
		sum-=strlen2;
		for(j=1;j<=sum;j++)
		{
			if(j==1)
			{
				for(i=j;i<=strlen1;i++)
				{
					if(i!=strlen2)
					{
						break;
					}
					else
					{
						m++;
					}
				}
				break;
			}
		}
	}
	cout<<n-q<<endl<<n-2*q;
	return 0;
}
