#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+15;
ll n,q,ans;
string s[N][5],t,t1,t2;
void sol(){
	cin>>t>>t2;
	ll len=t.size();
	ans=0;
	for(int i=1;i<=n;i++){
		t1=t;
		if(t1.find(s[i][1])!=-1){
			ll l=t1.find(s[i][1]);
			ll r=l+s[i][1].size()-1;
			if(r>len-1)continue;
			for(int j=l;j<=r;j++){
				t1[j]=s[i][2][j-l];
			}
			if(t1==t2)ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		sol();
	}
	return 0;
}