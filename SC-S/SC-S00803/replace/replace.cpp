#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q,cnt;
map<string,int> mp;
string g[maxn][105];
int ou[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;cin>>a>>b;
		if(!mp[a]) mp[a]=++cnt;
		g[mp[a]][++ou[mp[a]]]=b;
	}
	while(q--){
		int ans=0;
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<'\n';break;
		}
		int w=a.size();int last,first=-1;
		for(int i=0;i<w;i++){
			if(a[i]!=b[i]){
				last=i;
				if(first==-1) first=i;
			} 
		}
		for(int i=0;i<=first;i++){
			for(int j=last;j<=w-1;j++){
				string la,al;
				for(int k=i;k<=j;k++){
					la+=a[k];al+=b[k];
				}
				if(mp[la]){
					for(auto v:g[mp[la]]){
						if(v==al) ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 