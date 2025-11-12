#include<bits/stdc++.h>
using namespace std;
const int N=505,M=998244353,MX=262144,MN=20;
int n,m,a[N],p[N],s[MN],pc[MX+5],ans,cnt;
long long f[MN][MX+5],jc[N];
char c[N];
void solve12(){
	for(int i=1;i<=MX;i++)pc[i]=pc[i>>1]+(i&1);
	f[0][0]=1;
	for(int s=1;s<(1<<n);s++){
		for(int x=1;x<=n;x++){
			if((1<<x-1)&s){
				for(int i=0;i<=pc[s];i++){
					if(i>0&&c[pc[s]]=='1'&&a[x]>pc[s]-i)f[i][s]=(f[i][s]+f[i-1][s^(1<<x-1)])%M;
					if(i<pc[s]&&(c[pc[s]]=='0'||a[x]<pc[s]-i))f[i][s]=(f[i][s]+f[i][s^(1<<x-1)])%M;
				}
			}
		}
	}
	for(int i=m;i<=n;i++)ans=(ans+f[i][(1<<n)-1]);
	cout<<ans<<"\n";
	exit(0);
}
void solve5(){
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%M;
	long long res=1;
	for(int i=1;i<=n;i++)p[a[i]]++;
	for(int i=1;i<=n;i++)p[i]+=p[i-1];
	for(int i=1;i<=n;i++){
		if(c[i]=='1'){
			ans=(ans+res*(n-p[i-1])%M*jc[n-cnt-1]%M)%M;
			res=res*(p[i-1]-cnt)%M;
			++cnt;
		}
	}
	cout<<ans<<"\n";
	exit(0);
}
void solve6(){
	for(int i=1;i<=n;i++){
		if(c[i]=='0'||a[i]==0){
			cout<<"0\n";
			exit(0);
		}
	}
	long long res=1;
	for(int i=2;i<=n;i++)res=res*i%M;
	cout<<res;
	exit(0);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=18)solve12();
	if(m==1)solve5();
	if(m==n)solve6();
	return 0;
}