#include<bits/stdc++.h>
using namespace std;
string s1[101],s2[101],t1,t2;
int n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=m;i++){
		cin>>t1>>t2;
		int ans=0;
		for(int j=1;j<=n;j++){
			string x=t1,y=t2;
			if(s1[j]==s2[j]){
				while(x==y){
					int p=x.find(s1[j]);
					if(p>=x.size()||p<0) break;
					x.erase(p,1);y.erase(p,1);
					ans++;
				}
			}else{
				int p=x.find(s1[j]);
				if(p>=x.size()||p<0) continue;
				x.erase(p,s1[j].size());
				x.insert(p,s2[j]);
				if(x==y) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
