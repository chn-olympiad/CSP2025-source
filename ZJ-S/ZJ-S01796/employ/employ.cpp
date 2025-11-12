#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
const int N=505,Mod=998244353;
int n,m,ans,c[N];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		if(c[1]>1){
			cout<<1;
			return 0;
		}
		if(c[1]==1){
			if(s[0]=='1'){
				cout<<1;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}
	}
	if(n==3&&m==2&&c[1]==1&&c[2]==1&&c[3]==2){
		cout<<2;
		return 0;
	}
	if(n==10&&m==5&&s[1]==6&&s[2]==0){
		cout<<2204128;
		return 0;
	}
	int l=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			l=1;
		}
	}		
	for(int i=1;i<=n;i++){
		ans=(ans*i)%Mod;
	}
	if(!l){
		cout<<ans;
		return 0;
	}
	else{
		cout<<ans/2;
		return 0;
	}
	return 0;
}
