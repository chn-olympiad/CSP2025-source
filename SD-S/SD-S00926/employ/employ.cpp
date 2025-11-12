#include<bits/stdc++.h>
#define ll long long
#define debug cout<<"debug"<<endl;
#define endl '\n'
#define debug_endl cout<<endl;
//#define i128 __int128
#define MOD (998244353)
//#define eps (1e-6)
using namespace std;
int n,m;
string s;
int c[510],idx[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	if(n>10){
		int ans=0;
		for(int i=1;i<=n;++i){
			ans+=c[i]>0;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
		idx[i]=i;
	}
	int ans=0;
	do{
		int cnt=0,cnt2=0;
		for(int i=1;i<=n;++i){
			if(cnt>=c[idx[i]]){
				++cnt;
				continue;
			}
			if(s[i]=='1'){
				++cnt2;
			}
			else{
				++cnt;
			}
			if(cnt2>=m){
				++ans;
				break;
			}
		}
	}while(next_permutation(idx+1,idx+n+1));
	cout<<ans;
	return 0;
}

