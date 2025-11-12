#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N],b[N];
int main()
{
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	int z;
	string n;
	cin>>n>>z;
	int cnt=0;
	int len=n.size();
	for(int i=0;i<=len;i++)
	{
		if(n[i]>='0' && n[i]<='9')
		{
			z=n[i]-48;
			a[i]=z;
			cnt++;
			for(int j=0;j<cnt;j++)
			{
				if(a[i]>=0 && a[i]<=0) 
				{
					b[i]=a[i];
					cout<<j;
				}
			}
		}
	} 

//	sort(a,a+cnt+1);
//	for(int j=0;j<cnt;j++)
//	{
//		for(int i=cnt;i>0;i--)
//		{ 
//			cout<<a[i];
//		} 
//	}
	return 0;
}
