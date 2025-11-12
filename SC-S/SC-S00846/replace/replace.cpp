#include<bits/stdc++.h>
using namespace std;
string a[101010],b[101010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(m--){
		int ans=0;
		string x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			if(x.size()<a[i].size()) continue;
			for(int j=0;j<=x.size()-a[i].size();j++){
				string nxt="";
				for(int k=j;k<j+a[i].size();k++) nxt+=x[k];
				if(nxt==a[i]){
					string z=x;
					for(int k=j;k<j+b[i].size();k++) z[k]=b[i][k-j];
//					cout<<x<<" "<<nxt<<" "<<z<<endl;
					ans+=(z==y);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}