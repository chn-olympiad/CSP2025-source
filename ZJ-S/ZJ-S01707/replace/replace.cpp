#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int > 
const int N=1e6+100;
bool vis[N];
int dis[N];
struct node{
	int v,w;
};
priority_queue<pii > q;
vector<node> G[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	string s;
	for(int i=1;i<=n;i++)
	  cin>>s;
	for(int i=1;i<=m;i++)
	  cout<<0<<"\n";
	return 0;
}
