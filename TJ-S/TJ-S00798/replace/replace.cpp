#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[100010],t[100010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i]>>t[i];
	string x,y;
	cin>>x>>y;
	int ret=0;
	for(int i=0;i<n;i++){
		for(int j=2;j<=n;j++){
			for(int k=i;k<n && k<i+s[j].size();k++){
				x=s[j];
			}
			if(x==y) ret++;;
		}
	}
	cout<<ret;
	return 0;
}

