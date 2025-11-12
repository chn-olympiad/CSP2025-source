#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n,m;
int c[510];
vector<int> opt;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		opt.push_back(i);
	}
	int ans=0;
	do{
		int dead=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||c[opt[i-1]]<=dead){
				dead++;
			}else{
				cnt++;
			}
		}
		ans+=(cnt>=m);
	}while(next_permutation(opt.begin(),opt.end()));
	cout<<ans;
	return 0;
}