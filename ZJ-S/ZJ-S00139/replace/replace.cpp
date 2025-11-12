#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace l_mid_r{
	const int N=205,mod=1e9+3,K=13;
	int n,m[N],len,T,key[N],now[2];
	string s[N][2];
	string t1,t2;
	int gt(int x){return (x%mod+mod)%mod;}
	int ksm(int x,int y){
		int cnt=1;
		while(y){
			if(y&1) cnt*=x,gt(cnt);
			x*=x,x%=mod,y>>=1;
		}
		return cnt;
	}
	int solve(int u){
		int key_t1=0,key_t2=0,cnt=0,v=0;
		now[0]=now[1]=0;
		for(int i=1;i<=len;i++) key_t1=gt(key_t1*K+(t1[i]-'a'));
		for(int i=1;i<=len;i++) key_t2=gt(key_t2*K+(t2[i]-'a'));
		for(int i=1;i<=m[u];i++) now[0]=gt(now[0]*K+(s[u][0][i]-'a'));
		for(int i=1;i<=m[u];i++) now[1]=gt(now[1]*K+(s[u][1][i]-'a'));
		for(int i=1;i<=m[u];i++) v=gt(v*K+(t1[i]-'a'));
		//~ cout << t1 << "\n" << s[u][0] << "\n";
		//~ if(u==1) printf("%lld %lld\n",v,now[0]);
		for(int i=m[u];i+m[u]-1<=len;i++){
			if(i!=m[u]) v=gt((v-t1[i-m[u]+1]*ksm(K,m[u]-1))*K+t1[i]);
			if(v!=now[0]) continue;
			if(key_t1-ksm(now[0],len-i-m[u])+ksm(now[1],len-i-m[u])==key_t2) cnt++;
		}
		return cnt;
	}
	int main(){
		cin >> n >> T;
		for(int i=1;i<=n;i++){
			cin >> s[i][0] >> s[i][1];
			m[i]=s[i][0].size();
			s[i][0]="0"+s[i][0];
			s[i][1]="0"+s[i][1];
			for(int j=1;j<=m[i];j++) key[i]=(key[i]*K+(s[i][0][j]-'a'))%mod;
		}
		while(T--){
			cin >> t1 >> t2;
			len=t1.size(),t1="0"+t1,t2="0"+t2;
			int ans=0;
			for(int i=1;i<=n;i++) ans+=solve(i);
			cout << ans;
		}
		return 0;
	}
}
signed main(){return l_mid_r::main();}
