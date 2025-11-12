#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mk make_pair
struct Node
{
	int a,b,c;
}p[100010];
int n;
ll ans;
vector<Node> q1,q2,q3;
bool cmp1(Node x,Node y){return x.a-max(x.c,x.b)<y.a-max(y.c,y.b);}
bool cmp2(Node x,Node y){return x.b-max(x.a,x.c)<y.b-max(y.a,y.c);}
bool cmp3(Node x,Node y){return x.c-max(x.a,x.b)<y.c-max(y.a,y.b);}
void solve()
{
	ans=0;
	q1.clear();
	q2.clear();
	q3.clear();
	cin>>n;
	int s1=0,s2=0,s3=0;
	for(int i=1;i<=n;++i)
	{
		cin>>p[i].a>>p[i].b>>p[i].c;
		int maxn=max({p[i].a,p[i].b,p[i].c});
		if(p[i].a==maxn)
		{
			s1++;
			ans+=p[i].a;
			q1.pb(p[i]);
		}
		else if(p[i].b==maxn)
		{
			s2++;
			ans+=p[i].b;
			q2.pb(p[i]);
		}
		else
		{
			s3++;
			ans+=p[i].c;
			q3.pb(p[i]);
		}
	}
	if(s1>n/2)
	{
		sort(q1.begin(),q1.end(),cmp1);
		for(int i=0;i<s1-n/2;++i)ans-=q1[i].a-max(q1[i].b,q1[i].c);
	}
	else if(s2>n/2)
	{
		sort(q2.begin(),q2.end(),cmp2);
		for(int i=0;i<s2-n/2;++i)ans-=q2[i].b-max(q2[i].a,q2[i].c);
	}
	else if(s3>n/2)
	{
		sort(q3.begin(),q3.end(),cmp3);
		for(int i=0;i<s3-n/2;++i)ans-=q3[i].c-max(q3[i].b,q3[i].a);
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}//100pts,124min
