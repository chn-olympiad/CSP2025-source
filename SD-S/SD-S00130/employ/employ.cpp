#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[510],p[510],f[300010][21],fac[100010],inv[100010],infac[100010];
char s[510];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int A(int x,int y){
	if(x<0||y<0||x<y)return 0;
	return fac[x]*infac[x-y]%mod;
}
int C(int x,int y){
	if(x<0||y<0||x<y)return 0;
	return fac[x]*infac[x-y]%mod*infac[y]%mod;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	int tes=0;
	for(int i=1;i<=n;i++)tes+=s[i]-'0';
	fac[0]=inv[1]=infac[0]=1;
	for(int i=1;i<=100000;i++)fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<=100000;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=100000;i++)infac[i]=infac[i-1]*inv[i]%mod; 
	if(n<=18){
		f[0][0]=1;
		for(int i=0;i<(1<<n)-1;i++){
			int id=__builtin_popcountll(i);
			for(int j=0;j<=id;j++)
				for(int k=0;k<n;k++)if(!(i>>k&1)){
					if(s[id+1]=='0')add(f[i|(1<<k)][j+1],f[i][j]);
					else add(f[i|(1<<k)][j+(j>=a[k+1])],f[i][j]);
				}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++)add(ans,f[(1<<n)-1][i]);
		return cout<<ans,0;
	}
	if(m==n){
		if(tes<n||!a[1])return puts("0"),0;
		return cout<<fac[n],0;
	}
	if(tes<=18){
		vector<int> v;
		for(int i=1;i<=n;i++)if(s[i]=='1')v.push_back(i);
		int tans=0;
		for(int i=0;i<(1<<tes);i++)if(__builtin_popcountll(i)>=m){
			int id=0;
			vector<int> vv;
			for(int j=0;j<tes;j++)if(i>>j&1){
				id++;
				vv.push_back(n-(upper_bound(a+1,a+n+1,v[j]-id)-a)+1);
			}
			vv.push_back(0);
			f[0][0]=1;
			for(int j=0;j<id;j++){
				for(int k=0;k<=j+1;k++)f[j+1][k]=0;
				for(int k=0;k<=j;k++)if(f[j][k])
					for(int ii=k;ii<=j+1;ii++)(f[j+1][ii]+=f[j][k]*A(vv[j]-vv[j+1],ii-k)%mod*C(j+1-k,j+1-ii))%=mod;
			}
			(tans+=f[id][id]*fac[n-id]%mod*(id%2==m%2?C(id,id-m):mod-C(id,id-m)))%=mod;
		}
		return cout<<tans,0;
	}
	cout<<0;
}
