#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
const int N=505; 
int n,m,ans;
string s;
void dfs(vector<int>v,int zt,int sum,int idx){
	if(idx==n&&sum>=m){
		++ans;
		return;
	}
	for(int i=0;i<(int)v.size();i++){
		if(v[i]==-1)continue;

		int now=v[i];
		v[i]=-1;
		if(now>zt){
			if(s[idx]=='0')dfs(v,zt+1,sum,idx+1);
			else dfs(v,zt,sum+1,idx+1);
		}else {
		dfs(v,zt+1,sum,idx+1);continue;}
		v[i]=now;
	}
	
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fre("employ");
	cin>>n>>m>>s;
	vector<int>c(n);
	for(int i=0;i<n;i++)cin>>c[i];
	dfs(c,0,0,0);
	cout<<ans<<"\n";
	return 0;
} 