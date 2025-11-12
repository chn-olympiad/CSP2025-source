#include<bits/stdc++.h>
using namespace std;
int n,k;
long long sc;
int a[500010];
int _xor(int _a,int _b)
{
	int a2[10001],b2[10001],cnt1=1,cnt2=1;
	int l1=_a,l2=_b;
	while(l1)
	{
		a2[cnt1]=l1%2;
		l1/=2;
		cnt1++;
	}
	while(l2)
	{
		b2[cnt2]=l2%2;
		l2/=2;
		cnt2++;
	}
	int c[10001];
	for(int i=1;i<=max(cnt1,cnt2);i++)
	{
		if((a2[i]==1&&b2[i]==1)||(a2[i]==0&&b2[i]==0))
			c[i]==0;
		else
			c[i]==1;
	}
	int sum=0;
	for(int i=1;i<=max(cnt1,cnt2);i++)
		if(c[i]==1)
			sum+=pow(2,i-1);
	return sum;
}
bool _find(int _i,int _j,int k)
{
	int n;
	if(_i==_j&&a[_i]==k)
		return 1;
	if(_i==_j&&a[_i]!=k)
		return 0;
	if(k==0)
		return 0;
	for(int b=_i;b+1<=_j;b++)
		n=_xor(a[b],a[b+1]);
	if(n==k)
		return 1;
	return 0;
}
int main()
{ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(_find(i,j,k))	
			{
				sc++;
//				cout<<a[i]<<" "<<a[j]<<" "<<k<<endl;
				i=j;
				break;
			}
		}
	}
	printf("%.d",sc);
	return 0;
}
