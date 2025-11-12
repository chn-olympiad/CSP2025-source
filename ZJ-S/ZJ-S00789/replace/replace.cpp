#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1[200200],s2[200200],t1[5005000],t2[5005000];
bool f(int a,int b,int c,int d,int ei,int ej){
	for(int i=0;i<=b-a;i++){
		if(s1[ej][a+i]!=t1[ei][c+i]||s2[ej][a+i]!=t2[ei][c+i]) return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=m;i++){
		cin>>t1[i]>>t2[i];
		if(t1[i].size()!=t2[i].size()){
			cout<<0<<'\n';
			continue;
		}
		int minn=t1[i].size()+1;
		int maxx=0;
		int ans=0;
		for(int j=0;j<t1[i].size();j++){
			if(t1[i][j]!=t2[i][j]){
				minn=min(minn,j);
				maxx=max(maxx,j);
			}
		}
		for(int j=1;j<=n;j++){
			if(s1[j].size()!=s2[j].size()) continue;
			if(s1[j].size()<maxx-minn+1) continue;
			for(int k=0;k<s1[j].size()-maxx+minn;k++){
				if(f(k,k+maxx-minn,minn,maxx,i,j)==0) continue;
				if(f(0,k-1,minn-k,minn-1,i,j)==0) continue;
				if(f(k+maxx-minn+1,s1[j].size()-1,maxx+1,s1[j].size()-1+minn-k,i,j)==0) continue;
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
