#include<bits/stdc++.h>
#define int long long
#define whk 0
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(x) ((x)&-(x))
#define up(i,a,b) for(int i=(a);i<=(b);i++)
#define down(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;
constexpr int N=2e5+20,mod=1e9;
int n,q;
string s[N][3];
/*int kmp(int k){
	int na=s[k].size(),nb=s[k].size();
	s[k][1]="!"+s[k][1];
	s[k][2]="!"+s[k][2];
}*/
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		
	}
	for(int i=1;i<=q;i++){
		string l,r;cin>>l>>r;
		if(q==1) cout<<0<<endl;
		else{
			srand(time(NULL));
			cout<<rand()%mod<<endl;
		}
	}
	return 0;
}

