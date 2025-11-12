#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const int N=5e2+5,M=1e6+5,p=998244353;
int T=1;
int n,m,f1=1;
string s;
int a[N];
int tr[N];
i64 F[N];
void add(int x){
	for(;x<=n;x+=x&-x) tr[x]++;
}
int query(int x){
	int ret=0;
	for(;x;x-=x&-x) ret+=tr[x];
	return ret;
}
void solA(){
	
}
void solC(){
	i64 ans=1;
	int ss=0;
	for(int i=1;i<=n;i++) add(a[i]+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			ans=ans*(query(i)-ss)%p;
			ss++;
		}
	}
	ans=ans*F[n-ss]%p;
	ans=((F[n]-ans)%p+p)%p;
	cout<<ans<<"\n";
} 
void solD(){
	int fl=0;
	for(int i=1;i<=n;i++) if(s[i]=='0'||!a[i]) fl=1;
	cout<<(fl?0:F[n])<<"\n";
}
int b[N];
void solE(){
	int ans=0;
	for(int i=1;i<=n;i++) b[i]=i;
	do{
		int ss=0;
		for(int i=1;i<=n;i++) if(s[i]=='0'||ss>=a[b[i]]) ss++;
		if(n-ss>=m) ans++;
	}while(next_permutation(b+1,b+1+n));
	cout<<ans<<"\n";
}
int f[M][20];
int cc[M];
int lg[M];
void solF(){
	int ans=0;
	f[0][0]=1;
	cc[0]=0;
	for(int i=1;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<1<<n;i++){
		cc[i]=cc[i-(i&-i)]+1;
		for(int t=i,o=i&-i,id;t;t-=o,o=t&-t){
			id=lg[o];
			for(int j=0;j<=cc[i];j++){
				if(j&&(s[cc[i]]=='0'||a[id]<=j-1)) f[i][j]=(f[i][j]+f[i-o][j-1])%p;
				if(j<cc[i]&&s[cc[i]]=='1'&&a[id]>j) f[i][j]=(f[i][j]+f[i-o][j])%p;
			}
		}
	}
	for(int i=0;i<1<<n;i++){
		for(int j=0;j<=n;j++) cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
	}
	for(int i=0;i<=n-m;i++) ans=(ans+f[(1<<n)-1][i])%p;
	cout<<ans<<"\n";
}
void solve(){
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	F[1]=1;
	for(int i=2;i<=n;i++) F[i]=F[i-1]*i%p;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) if(s[i]=='0') f1=0;
	if(m==1){
		solC();
		return;
	}
	if(m==n){
		solD();
		return;
	}
	if(n<=10){
		solE();
		return;
	}
	if(n<=18){
		solF();
		return;
	}
	if(f1) {
		solA();
		return;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	 
	while(T--) solve();
	return 0;
} 