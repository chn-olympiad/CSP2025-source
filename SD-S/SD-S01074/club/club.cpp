#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
/*====================*/
const int N=1e5+10;
/*====================*/
int n;
struct Node{
	int id;
	int k[3];
}node[N];
vector<int>v[3];
int tot[4];
priority_queue<int>q;
/*====================*/
int maxx(Node x)
{
	if(x.k[0]>x.k[1])
	{
		if(x.k[0]>x.k[2])return 0;
		return 2;
	}
	if(x.k[1]>x.k[2])return 1;
	return 2;
}
int maxm(Node x)
{
	return x.k[maxx(x)];
}
void solve()
{
	ll sum=0;
	for(int i=0;i<=2;i++)
	{
		v[i].clear();
		tot[i]=0;
	}
	while(!q.empty())q.pop();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		node[i].id=i;
		scanf("%d%d%d",&node[i].k[0],&node[i].k[1],&node[i].k[2]);
		int maxi=maxx(node[i]);
		v[maxi].push_back(node[i].id);
		tot[maxi]++;
		sum+=maxm(node[i]);
	}
	int ot=-1;
	if(tot[0]>n/2)ot=0;
	if(tot[1]>n/2)ot=1;
	if(tot[2]>n/2)ot=2;
	if(ot==-1)
	{
		printf("%lld\n",sum);
		return;
	}
	for(auto i:v[ot])
	{
		int maxk=0;
		for(int j=0;j<=2;j++)
		{
			if(ot==j)continue;
			maxk=max(maxk,node[i].k[j]);
		}
		q.push(maxk-node[i].k[ot]);
	}
	while(tot[ot]>n/2)
	{
		sum+=q.top();
		q.pop();
		tot[ot]--;
	}
	printf("%lld\n",sum);
}
/*====================*/
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
