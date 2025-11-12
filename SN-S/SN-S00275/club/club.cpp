#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+10;

int n; ll ans;
struct nod{int i,v;} a[N][3];
bool cmp(nod a,nod b) {return a.v>b.v;} 

priority_queue<int> q[4];

void work()
{
	cin>>n; ans=0;
	for (int i=1;i<=3;i++) while (!q[i].empty()) q[i].pop();
	for (int i=1;i<=n;i++) for (int j=1;j<=3;j++) 
	{
		cin>>a[i][j].v;
		a[i][j].i=j;
	}
	
	for (int i=1;i<=n;i++)
	{
		sort(a[i]+1,a[i]+4,cmp);
		ans+=a[i][1].v; q[a[i][1].i].push(a[i][2].v-a[i][1].v);
	}
	
	for (int i=1;i<=3;i++) while (q[i].size()>n/2) 
	{
		ans+=q[i].top(); 
		q[i].pop();
	}
	
	cout<<ans<<"\n";
	
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while (t--) work();
	
	return 0;
}




