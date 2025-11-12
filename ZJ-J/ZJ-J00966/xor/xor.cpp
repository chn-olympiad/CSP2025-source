#include<bits/stdc++.h>
#define f(i,l,r) for(int i=(l);i<=(r);++i)
#define g(i,l,r) for(int i=(l);i>=(r);--i)
using namespace std;

int n,k;
int a[500010];
int s,num;

int main(){
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int l = 1;l<=n;l++)
	{
		s = a[l];
		if(a[l] == k)
		{
			num++;
		}
		for(int r = l+1;r<=n;r++)
		{
			s = s^a[r];
			if(s == k)
			{
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}

