#include <bits/stdc++.h>
using namespace std;
long long ans,n,m,jl1[100],pp[100],ii[100];
string s;
bool pd(){
	int jl=0,lj=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'&&jl<ii[jl1[i]]){
			lj++;
			jl=0;
		}
		else{
			jl++;
		}
//		cout<<jl1[i]<<" ";
	}
//	cout<<"\n";
	return (lj==m);
}
void dfs(int gs){
	if(gs==n){
		ans+=pd();
	}
	for(int i=1;i<=n;i++){
		if(pp[i]==0){
			pp[i]=1;
			jl1[gs+1]=i;
			dfs(gs+1);
			pp[i]=0;
		}
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>ii[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}

