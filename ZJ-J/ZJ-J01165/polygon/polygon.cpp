#include<bits/stdc++.h>
using namespace std;
int s[5001],n,f,ans;
void dfs(int dep,int m_v,int sum,int cnt,bool e){
	if(sum>(m_v*2) and cnt>=3 and e) ans++,e=0;
	if(dep==n) return;
	dfs(dep+1,m_v,sum,cnt,e);
	dfs(dep+1,max(m_v,s[dep]),sum+s[dep],cnt+1,1);
}int main(){
	ios::sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	dfs(0,0,0,0,1);
	cout<<ans;
}
