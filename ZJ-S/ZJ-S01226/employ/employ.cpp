#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
const int mod=998244353;
int n,m;
int s[N],c[N];
unsigned long long jc[N];
unsigned long long Pow(unsigned long long a,int b){
	unsigned long long res=1;
	while(b){
		if(b&1) res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
int sl[N];
void solve(){
	int ans=0;
	do{
		int out=0,res=0;
		for(int i=1;i<=n;i++){
			if(out>=c[sl[i]]){
				out++;
				continue;
			}
			if(s[i]) res++;
			else out++;
			if(res==m){
				ans=(ans+1)%mod;
				break;
			}
		}
	}while(next_permutation(sl+1,sl+n+1));
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int tot=0;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		s[i]=x-'0';
		tot+=s[i];
	}	
	jc[0]=1;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		num+=(c[i]==0);
		sl[i]=i;
		jc[i]=jc[i-1]*i%mod;
	}
	if(tot<m||n-num<m) cout<<0;
	else if(tot==n) cout<<jc[n-num];//GG
	else if(m==n) cout<<0;
	else solve();//TLE
	return 0;
}
