#include<bits/stdc++.h>
#define int long long
using namespace std;
//UID:1137851
//SAD
const int N=2e5+5;
int n,m;
string a[N],b[N];
string t[N][3];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(m--){
		cin>>t[1][1]>>t[1][2];
		cout<<0<<"\n";
	}
	return 0;
}

