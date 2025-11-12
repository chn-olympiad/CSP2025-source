#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,q,l,r,ans;
string s1[N],s2[N],str,strr;
void solve(){
	cin>>str>>strr,ans=0;
	if(str.size()!=strr.size()){cout<<"0\n";return ;}
	int L=str.size();
	for(int i=0;i<L;i++)
		if(str[i]!=strr[i]){
			l=i;break;}
	for(int i=L-1;~i;i--)
		if(str[i]!=strr[i]){
			r=i;break;}
	for(int i=1;i<=n;i++){
		int ll=s1[i].size();
		if(ll<r-l+1)continue;
		if(ll>L)continue;
//		cout<<max(0,r-ll+1)<<" "<<min(l,L-ll)<<"\n";
		for(int j=max(0,r-ll+1);j<=min(l,L-ll);j++){
			if((str.substr(j,ll)==s1[i])&&(strr.substr(j,ll)==s2[i])){
				ans++;break;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--)solve();
	return 0;
}