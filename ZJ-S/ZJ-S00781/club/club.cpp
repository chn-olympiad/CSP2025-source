#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int q,a[N][4],t[10],dis[N];
vector<int> G[10];
void solve(){
	memset(dis,0,sizeof(dis));
	memset(G,0,sizeof(G));
	int n,ans=0;
	cin>>n;
	int op=n/2;
	t[1]=t[2]=t[3]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		int x=max(max(a[i][1],a[i][2]),a[i][3]);
		ans+=x;
		if(x==a[i][1]){
			t[1]++;
			G[1].push_back(i);
			
		}
		else if(x==a[i][2]){
			t[2]++;
			G[2].push_back(i);
		}
		else{
			t[3]++;
			G[3].push_back(i);
		}
	}
	if(t[1]<=op&&t[2]<=op&&t[3]<=op){
		cout<<ans<<"\n";
		return;
	}
	int f;
	if(t[1]>op) f=1;
	else if(t[2]>op) f=2;
	else f=3;
	int sz=t[f]-op;
	int m=G[f].size();
	for(int i=0;i<m;i++){
		int to=G[f][i];
		int x=a[to][1],y=a[to][2],z=a[to][3];
		int jl;
		if(f==1) jl=min(x-y,x-z);
		else if(f==2) jl=min(y-x,y-z);
		else jl=min(z-x,z-y);
		dis[i+1]=jl;
	}
	sort(dis+1,dis+m+1);
	for(int i=1;i<=sz;i++)
		ans-=dis[i];
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>q;
	while(q--)
		solve();
	return 0;
}