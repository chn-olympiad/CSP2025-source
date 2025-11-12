#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=100010;
int n,m;
string s;
ll num[maxn];
ll c[maxn];
ll mod=998244353;
int t;
vector<vector<int>> H;
vector<int> an;
int vis[15];

void dfs(int dep){
	if(dep>n){
		H.push_back(an);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		an.push_back(i);
		vis[i]=1;
		dfs(dep+1);
		an.pop_back();
		vis[i]=0;
	}
}
int ans=0;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		num[i]=s[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	dfs(1);
	for(auto t:H){
		int l=0;
		int tui=0;
		for(int i=0;i<n;i++){
			int Now=t[i];
			if(tui>=c[Now]){
				tui++;
			}else if(num[i+1]==0){
				tui++;
			}else{
				l++;
			}
		}
		if(l>=m){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}