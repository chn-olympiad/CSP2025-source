#include<bits/stdc++.h>
#define int long long int
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int n,q,ans;
string a,b,c[200005],d[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	IOS
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>c[i]>>d[i];
	}
	if(n*q<=1e9){
		for(int i=0;i<q;i++){
			cin>>a>>b;
			ans=0;
			for(int j=0;j<n;j++){
				if(a==c[j]&&b==d[j]){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	else{
		for(int i=0;i<q;i++){
			cout<<"0\n";
		}
	}
	return 0;
}
