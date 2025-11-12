#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inline
const ll N=2e5+10;
ll n;
string s[N][2];
ll siz[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n;ll q;
	cin>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		siz[i]=s[i][1].size();
		s[i][1]=" "+s[i][1];
		s[i][2]=" "+s[i][2];
	}
	
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		ll m=t1.size();
		t1=" "+t1;
		t2=" "+t2;
		ll ans=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				bool fl=1;
				if(i+siz[j]-1>m) continue;
				for(int k=i;k<i+siz[j];k++){
					if(s[j][1][k-i+1]!=t1[k]){
						fl=0;
						break;
					}
				}
				if(fl){
					string tmp=t1;
					for(int k=i;k<i+siz[j];k++){
						tmp[k]=s[j][2][k-i+1];
					}
//					if(i==3) cout<<tmp<<" "<<t2;
					if(tmp==t2){
//						cout<<i<<" "<<j<<"\n";
						ans++;	
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

