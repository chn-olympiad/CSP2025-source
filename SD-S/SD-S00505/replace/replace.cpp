#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
pair<string,string> a[N];
signed main(){
	
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
int n,q;
cin>>n>>q;
for(int i=1;i<=n;i++){
	cin>>a[i].first>>a[i].second;

}
	for(int i=1;i<=q;i++){
		int ans=0; 
		string t1,t2;
		cin>>t1>>t2;
		for(int j=1;j<=n;j++){
			if(a[j].first==t1&&t2==a[j].second){
					ans++;
			}
		}
		cout<<ans<<'\n';
	}
	   return 0;
}


