#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+5;

int n,m,k;
struct node{
	int v,w;
	bool tong;
};
vector<node>ve[maxn];
bool flag[maxn];

void dfs1(int x){
	for(int i=0;i<ve[x].size();i++){
		node edg=ve[x][i];
		if(flag[edg.v]==0&&edg.tong==1){
			flag[edg.v]=1;
			dfs1(edg.v);
		}
	}
	return;
}

bool check1(){
	for(int i=1;i<=n;i++)flag[i]=0;
	flag[1]=1;
	dfs1(1);
	for(int i=1;i<=n;i++){
		if(flag[i]==0)return 0;
	}
	return 1;
}

ll dfs2(int x){
	ll ans=0;
	for(int i=0;i<ve[x].size();i++){
		node edg=ve[x][i];
		if(check1()==1)ans=max(ans,dfs2(edg.v));//off
		ve[x][i].tong=0;
		if(check1()==1)ans=max(ans,dfs2(edg.v)+edg.w);//on
		ve[x][i].tong=1;
	}
	return ans;
}


int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	ll ppp=0;
	for(int i=1;i<=m;i++){
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		ppp+=ww;
		ve[uu].push_back((node){vv,ww,1});
	}
	cout<<ppp-dfs2(1);
	return 0;
}

