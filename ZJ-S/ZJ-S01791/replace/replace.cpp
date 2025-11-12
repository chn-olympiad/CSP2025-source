#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10,p=9999991,mod=1e9+7;
int n,m,H1[N],H2[N],P[N];
map<pair<int,int>,int>mp;
int Hash(string s){
	int h=s[0];
	for(int i=1;i<s.size();++i){
		h=(1ll*h*p%mod+s[i])%mod;
	}
	return h;
}
void calc(string s,int *H){
	for(int i=1;i<s.size();++i){
		H[i]=(1ll*H[i-1]*p%mod+s[i])%mod;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		int H1=Hash(s);
		cin>>s;
		int H2=Hash(s);
		mp[{H1,H2}]++;
//		cout<<H1<<' '<<H2<<' '<<'\n';
	}
	P[0]=1;
	for(int i=1;i<=5e6;++i){
		P[i]=1ll*P[i-1]*p%mod;
	}
	while(m--){
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<"0\n";
			continue;
		}
		int len=s.size();
		s=" "+s,t=" "+t;
		calc(s,H1),calc(t,H2);
//		printf("SPC:%d\n",(H1[4]-1ll*H1[2]*P[2]%mod+mod)%mod);
		long long ans=0;
		for(int i=1;i<=len;++i){
			for(int j=len;j>=i;--j){
//				cout<<i<<' '<<j<<' '<<(H1[j]-1ll*H1[i-1]*P[j-i+1]%mod+mod)%mod<<' '<<(H2[j]-1ll*H2[i-1]*P[j-i+1]%mod+mod)%mod<<'\n';
//				cout<<mp[{(H1[j]-1ll*H1[i-1]*P[j-i+1]%mod+mod)%mod,(H2[j]-1ll*H2[i-1]*P[j-i+1]%mod+mod)%mod}]<<'\n';
				ans+=mp[{(H1[j]-1ll*H1[i-1]*P[j-i+1]%mod+mod)%mod,(H2[j]-1ll*H2[i-1]*P[j-i+1]%mod+mod)%mod}];
				if(s[j]!=t[j]){
					break;
				}
			}
			if(s[i]!=t[i]){
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}