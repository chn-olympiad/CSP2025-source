#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+100;
typedef long long ll;
typedef pair<ll,ll> pr;
int n;
struct node
{
	int a,b,c;
}a[MAXN];
int to[MAXN];
pr b[MAXN],c[MAXN],d[MAXN];
bool cmp(node x,node y)
{
	if(x.a==y.a&&x.a==y.b)return x.c<y.c;
	if(x.a==y.a)return x.b<y.b;
	return x.a>y.a; 
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	sort(a+1,a+n+1,cmp);
	//for(int i=1;i<=n;i++)cout<<"NEW A  "<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<endl;
	ll x=0;
	for(int i=1;i<=n;i++)to[i]=1;
	for(int i=1;i<=n;i++)
	{
		b[i].first=a[i].b-a[i].a;
		b[i].second=i;
		//x+=b[i].first;
	}
	sort(b+1,b+n+1,greater<pr>());
	for(int i=1;i<=n/2;i++)to[b[i].second]=2;
	//cout<<"INFO "<<x<<endl;
	//for(int i=1;i<=n;i++)cout<<"INFO#1  "<<i<<" "<<to[i]<<endl;
	 
	for(int i=1;i<=n;i++)
	{
		if(to[i]==1)c[i].first=a[i].c-a[i].a;
		//else if(to[i]==2)c[i].first=a[i].c-a[i].b;
		c[i].second=i;
		//cout<<c[i].first<<endl;
	}
	
	sort(c+1,c+n+1,greater<pr>());
	for(int i=1;i<=n/2;i++)
	{
		if(c[i].first>0)to[c[i].second]=3;
		//cout<<c[i].first<<endl; 
	}
	ll p=0;
	for(int i=1;i<=n;i++)
	{
		if(to[i]==1)p+=a[i].a;
		else if(to[i]==2)p+=a[i].b;
		else p+=a[i].c;
		//cout<<"INFO "<<i<<" "<<to[i]<<endl;
	}
	cout<<p<<endl;
}
int main()
{
	freopen("myans.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
}
/*
1
10
20 145 189
24 153 163
19 62 161
20 993 197
83 105 54
35 146 179
61 134 166
87 5 43
9 31 99
164 53 109

*/
