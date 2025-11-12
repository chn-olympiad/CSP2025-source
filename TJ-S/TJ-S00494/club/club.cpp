#include<bits/stdc++.h>
#define int long long
const int N = 1e5+10;
using namespace std;
int n,t;
int num1,num2,num3;
struct node
{
	int ans;
	int id;
	bool l;
};
node a[N],b[N],c[N];
bool cmp(node a,node b)
{
	if(a.ans==b.ans) return a.id<b.id;
	else return a.ans>b.ans;
}
int dfs1(node a[],node b[],node c[],int num)
{
	int k=0;
	for(int j=1;j<=n;j++)
	{
		if(k>n/2)
		{
			break;
		}
		if(!a[j].l&&a[j].ans>=b[j].ans&&a[j].ans>=c[j].ans){
			num+=a[j].ans;
			a[j].l=true;
			k++;
		}
	}
	return num;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		num1=num2=num3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].ans>>b[i].ans>>c[i].ans;
			a[i].l=false,b[i].l=false,c[i].l=false;
			a[i].id=i,b[i].id=i,c[i].id=i;
		}
		num1=dfs1(a,b,c,0);
		num2=dfs1(b,a,c,0);
		num3=dfs1(c,a,b,0);
		cout << num1+num2+num3 << '\n';
 	}
	return 0;
}
