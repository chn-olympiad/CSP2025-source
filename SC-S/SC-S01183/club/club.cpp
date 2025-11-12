#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e5+10;
struct node{
	int a,b,c,d;
}a[N];
int ans,n;
void dfs(int k,int sum,int x,int y,int z)
{
	if(k==n) 
	{
		ans=max(ans,sum);
		return;
	}
	k++;
	//cout<<x<<' '<<y<<' '<<z<<endl;//调试用，提交记得删 
	if(x<n/2) dfs(k,sum+a[k].a,x+1,y,z);
	if(y<n/2) dfs(k,sum+a[k].b,x,y+1,z);
	if(z<n/2) dfs(k,sum+a[k].c,x,y,z+1);
}//20pts
bool cmp_A(node x,node y)
{
	if(x.a!=y.a) return x.a>y.a;
	else if(x.b!=y.b) return x.b>y.b;
	return x.c>y.c;
}
bool cmp_B(node x,node y)
{
	return x.d>y.d;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		ans=0;
		bool flag_A=1,flag_B=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].d=a[i].a-a[i].b;
			if(a[i].b) flag_A=0;
			if(a[i].c) flag_A=flag_B=0; 
		}
		if(flag_A)
		{
			sort(a+1,a+n+1,cmp_A);
			for(int i=1;i<=n/2;i++) ans+=a[i].a;
			cout<<ans<<endl;
		}//5pts
		else if(flag_B)
		{
			sort(a+1,a+n+1,cmp_B);
			for(int i=1;i<=n/2;i++) ans+=a[i].a;
			for(int i=n/2+1;i<=n;i++) ans+=a[i].b;
			cout<<ans<<endl;
		}//15pts
		else
		{
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
