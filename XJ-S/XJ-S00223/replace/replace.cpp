#include <bits/stdc++.h>
using namespace std;
int n,q,ans,ll;
pair<string,string>pss[20020];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>pss[i].first>>pss[i].second;
		ll=pss[i].first.size();
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		ans=0;
		for(int i=1;i<=n;i++){
			if(pss[i].first==a && pss[i].second==b){
				ans++;
			}
			if(a[i]!=b[i]){
				int z=i+1;
				while(a[z]!=b[z] && z<=n){
					z++;
				}
				string ra="",rb="";
				for(int k=i;k<=z;k++){
					ra+=a[k];
					rb+=b[k];
				}
				for(int j=1;j<=n;j++){
					if(pss[j].first==ra && pss[j].second==rb){
						ans++;
					}
				}
			}
			
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
