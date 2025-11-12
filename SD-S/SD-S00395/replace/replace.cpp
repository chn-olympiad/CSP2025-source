#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,q,ans,vis[N];
string s1[N],s2[N],sa,sb,a,b;
bool xd(string a,string b){
	if(a.size()!=b.size()) return 0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]) return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>sa>>sb;
		int l=sa.size();
		ans=0;
		memset(vis,0,sizeof(vis));
		for(int j=0;j<l;j++){
			for(int k=1;k<=n;k++){
				int w=s1[k].size();
				if(j+w>l) continue;
				a=sa.substr(j,w);
				b=sb.substr(j,w);
				if(xd(a,s1[k])&&xd(b,s2[k])&&vis[k]==0){
					vis[k]=1;
					ans++;
				} 
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
