#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;i++)
#define UF(i,a,b) for(int i=a;i>=b;i--)
#define look_memory cerr<<abs(&M2-&M1)/1024.0/1024<<'\n'
#define look_time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<'\n'
using namespace std;
#define LL long long
bool M1;
const int mod=998244353;
/*
int ksm(int a,int b){
	
}
*/
const int N=550;
int n,m;
string s;
int p[N];
void Sub_A(){
	int cnt[N]={0},sum[N]={0};
	for(int i=1;i<=n;i++) cnt[p[i]]++;
	for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
	for(int i=1;i<=n;i++){
		if(sum[i]>i){
			cout<<0<<'\n';
			return ;
		}
	}
	
}
void solve(){
	cin>>n>>m>>s;
	bool flag=1;
	for(int i=0;i<n;i++) if(s[i]=='0') flag=0;
	for(int i=1;i<=n;i++) cin>>p[i];
	if(flag){
		int res=1;
		for(int i=2;i<=n;i++){
			res=(res*i)%mod;
		}
		cout<<res<<'\n';
	}
	Sub_A();
	return ;
}
bool M2;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int Time=clock();
	int T=1;
//  cin>>T;
	while(T--){
		solve();
	}
	look_memory;
	look_time;
	return 0;
}
/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

*/
