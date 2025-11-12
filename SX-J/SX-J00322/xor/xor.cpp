#include<bits/stdc++.h>
using namespace std;
long long n,k,m=0;
long long s=0,xx;
long long a[500005];
struct PII
{
	int st,en;
	int siz;
}skt[500005];
bool cmp(PII x,PII y)
{
	if(x.en==y.en) return x.siz<y.siz;
	else return x.en<y.en;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int x=a[i],j=i+1;
		while(x!=k&&j<n)
		{
			x=(x^a[j]);
			j++;
		}
		if(x==k)
		{
			skt[m].st=i; skt[m].en=j-1;
			skt[m].siz=j-i; m++;
		}
	}
	sort(skt,skt+m,cmp);
//	for(int i=0;i<m;i++) cout<<skt[i].st<<" "<<skt[i].siz<<"\n";
	xx=skt[0].en; s=1;
	for(int i=1;i<n;i++)
	{
		if(xx<skt[i].st)
		{
			s++;
			xx=skt[i].en;
		}
	}
	cout<<s;
	return 0;
}
/*
4 3
2 1 0 3

*/