#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5;
string s1[N],s2[N];
int n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=m;i++){
		string x,y;
		cin>>x>>y;
		ll ans=0,xs=x.size();
		for(int i=0;i<xs;i++){
			for(int j=1;j<=n;j++){
				//cout<<x.substr(i,s1[j].size())<<' '<<s1[j]<<'\n';
				if(x.substr(i,s1[j].size())==s1[j]){
					//cout<<i<<'*'<<'\n';
					int jo=i+s1[j].size();
					if(i+s1[j].size()>=xs)
						jo=xs;
					//cout<<x.substr(0,i)+s1[j]+x.substr(jo,xs-jo)<<'\n';
					if(x.substr(0,i)+s2[j]+x.substr(jo,xs-jo)==y){
						//cout<<i<<'*';
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}