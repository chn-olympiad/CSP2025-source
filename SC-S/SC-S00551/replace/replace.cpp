#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	unordered_map<string,int> m;
	string u,v;
	for(int i=1;i<=n&&cin>>u>>v;i++){
		m[u+" "+v]++;
	}
	for(int i=1;i<=q&&cin>>u>>v;i++){
		if(u.length()!=v.length()) {cout<<"0\n"; continue;}
		int len=min(u.length(),v.length()),sl=0,sr=len-1,ans=0;
		while(sl<len-1&&u[sl]==v[sl]) sl++;
		while(sr>0&&u[sr]==v[sr]) sr--;
		for(int j=0;j<=sl;j++){
			for(int l=sr;l<=len-1;l++){
				string sss=u.substr(j,l-j+1)+" "+v.substr(j,l-j+1);
				if(m.count(sss)) ans+=m[sss];
				//cout<<"<"<<u.substr(j,l-j+1)<<" "<<v.substr(j,l-j+1)<<" "<<m[u.substr(j,l-j+1)+" "+v.substr(j,l-j+1)]<<">";
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}