#include <bits/stdc++.h>
using namespace std;
const int N=1e5+12;
int T,n,maxn,sum;
int a1[N],a2[N],a3[N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		maxn=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		sort(a1+1,a1+n+1,cmp);
		for(int i=1;i<=maxn;i++)
		{
			sum+=a1[i];
		}
		cout<<sum<<endl;
		sum=0;
		return 0;
	}
 } 
