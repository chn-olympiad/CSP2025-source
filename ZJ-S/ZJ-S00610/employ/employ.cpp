#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int MOD=998244353;
int n,m,ans;
int s[N],c[N];
vector<int> a(1,0);
bool v[N];
bool check(){
	int cnt=0,tot=0;
	for(int i=1;i<=n;i++){
		if(tot>=c[a[i]])tot++;
		else if(!s[i])tot++;
		else cnt++;
	}
//	cout<<cnt<<'\n';
	return cnt>=m;
}
void dfs(int id){
	if(id==n+1){
		ans+=check();
		if(ans>=MOD)ans-=MOD;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			a.emplace_back(i);
			v[i]=1;
			dfs(id+1);
			a.pop_back();
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	string t;
	cin>>t;
	for(int i=0;i<n;i++)s[i+1]=t[i]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}