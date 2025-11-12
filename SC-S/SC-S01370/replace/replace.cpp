#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5+5;
string s1[N],s2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int sum=0;
		for(int i=1;i<=n;i++){
			int tt=t1.size(),ss=s1[i].size();
			for(int j=0;j<=(tt-ss);j++){
				string t=t1.substr(j,ss);
				string s=t1.substr(0,j)+s2[i]+t1.substr(j+ss);
				if(t==s1[i]&&s==t2) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
