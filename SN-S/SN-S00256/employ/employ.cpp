//Code Originally Designed by Zhang Aoyi, SN-S00256, NOI CSP-J/S 2025, Shaanxi Province
//Lang: C++, Time: 14:30~18:30, NPU Chang'an Campus
//Xi'an Aerospace City No.1 (Junior) High School
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
using namespace std;
//priority_queue<int>q;
//priority_queue<int,vector<int>,greater<int> >q;
int n,m;
string s;
int c[600];
bool spA=1;
bool exampleVis[19];
ll ans;
const int Mod=998244353;
void dfs(int xb,int exitN,int dayN,int employedN,bool vis[19],int depth){
	depth++;
	vis[xb]=1;
	//cout<<dayN<<" "<<xb<<" "<<employedN<<"\n";
	if(s[dayN]=='1'&&exitN<c[xb]){
		
		employedN++;
	}
	if(exitN>=c[xb]) exitN++;
	if(dayN==n){
		if(employedN>=m) ans++;
		if(ans==Mod) ans=0;
		//vis[xb]=0;
		return;
	}
	bool tvis[19];
	for(int i=0;i<=n;i++){
		tvis[i]=vis[i];
	}
	for(int i=1;i<=n;i++){
//		cout<<depth<<"vis:";
//		for(int j=1;j<=n;j++){
//			cout<<vis[j];
//		}
//		cout<<"\n\n";
		if(tvis[i]) continue;
		//cout<<"!"<<i<<"!";
		dfs(i,exitN,dayN+1,employedN,tvis,depth);
		//vis[i]=0;
	}
	//vis[xb]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
//	for(int i=1;i<=n;i++){
//		if(s[i]==0) spA=0;
//	}
//	if(spA){
//		cout<<n*(n-1);
//	}
	c[0]=1e9;
	dfs(0,0,0,0,exampleVis,0);
	cout<<ans;
	return 0;
}


