/*
StarLight_Yuran_ovo
我在等你 找到你 一直到大雾散去 多少次坠下谷底 也能抱住自己 山上的风 地心的力 生命向上长成了自己 那时你会看到 春野满地
重生 光
JROI 2023~无限
Starlight OI 2024~无限
RP++ 
648647291436
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int b[N];
int ans;
int maxx;
int lowbit(int x)
{
	return x&-x;
}
int main()
{
//	cout<<(0^2);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=1e3)
	{
		b[1]=a[1];
		for(int i=2;i<=n;i++)
		{
			b[i]=b[i-1]^a[i];
		}
		for(int r=1;r<=n;r++)
		{
	//		cout<<l<<' ';
			for(int l=maxx+1;l<=r;l++)
			{
				if(k==(b[r]^b[l-1]))
				{
					ans++;
					maxx=r;
					break;
				}
			}
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
