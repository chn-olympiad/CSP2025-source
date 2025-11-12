#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,Q,ans;
string s1[200005],s2[200005];
string t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(Q--){
		ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			if(t1==s1[i]&&t2==s2[i]) ans++;
		}
		cout<<ans<<endl; 
	}
	return 0;
}
//
