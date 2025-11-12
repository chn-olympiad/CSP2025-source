#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,pa[N],pb[N],len[N];
string s[N],t[N];
inline void solve(){
	string a,b;cin>>a>>b;
	int paa,pbb,m=a.size(),ans=0;
	for(int i=0;i<m;++i){
		if(a[i]=='b')
			paa=i;
		if(b[i]=='b')
			pbb=i;
	}
	for(int i=1;i<=n;++i){
		if(pb[i]-pa[i]==pbb-paa){
			if(pbb>paa){
				if(pa[i]<=paa&&(len[i]-pb[i])<=(m-pbb))ans++;
			}
			else{
				if(pb[i]<=pbb&&(len[i]-pa[i])<=(m-paa))ans++;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i]>>t[i];
		len[i]=s[i].size();
		for(int j=0;j<len[i];++j){
			if(s[i][j]=='b')
				pa[i]=j;
			if(t[i][j]=='b')
				pb[i]=j;
		}
	}
	while(q--)solve();
	return 0;
}
