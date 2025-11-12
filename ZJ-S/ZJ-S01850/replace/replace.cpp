#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10,M=5e6+10;
ll n,m,ans;
pair<string,string> s[N],q[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i].first>>s[i].second;
	for(int i=1;i<=m;i++)cin>>q[i].first>>q[i].second;
	if(m==1){
		ll k;
		string qf=q[1].first,qs=q[1].second;
		if(qf.size()!=qs.size()){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			k=qf.find(s[i].first);
			if(k!=-1){
				string c=qf,sf=s[i].second;
				for(int j=0;j<sf.size();j++){
					c[j+k]=sf[j]; 
				}
				if(c==qs)ans++;
			}
		}cout<<ans;
		return 0;
	}
	return 0;
}
