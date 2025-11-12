#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,ans,la,j;
string a,b,sa,aa[200010],bb[200010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>aa[i]>>bb[i];
	while(m--){
		cin>>a>>b;ans=0;
		la=a.size();
		for(i=1;i<=n;i++){
			if(aa[i].size()>la)continue;
			if(a.find(aa[i])==-1)continue;
			sa=a;
			sa.erase(a.find(aa[i]),aa[i].size());
			sa.insert(a.find(aa[i]),bb[i]);
			if(sa==b)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
