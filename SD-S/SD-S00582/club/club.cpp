#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,ans,cnt[5];
struct S
{
	int a,b,c;
}s[N];
int ma(S x)
{
	int a[3]={x.a,x.b,x.c};
	sort(a,a+3);
	return a[2];
}
int se(S x)
{
	int a[3]={x.a,x.b,x.c};
	sort(a,a+3);
	return a[1];
}
int mid(S x)
{
	if(x.a==ma(x)) return 1;
	if(x.b==ma(x)) return 2;
	return 3;
}
int f(S x)
{
	return ma(x)-se(x);
}
bool cmp(S a,S b)
{
	return f(a)>f(b);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d %d %d",&s[i].a,&s[i].b,&s[i].c);
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			cnt[mid(s[i])]++;
			if(cnt[mid(s[i])]>n/2) ans+=se(s[i]);
			else ans+=ma(s[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
