#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const long long mod=998244353;
long long n,m,f[20][20][N],c[20];
string s;
long long dfs(long long d,long long x,long long z){
	if(f[d][x][z]){
		return f[d][x][z];
	}
	if(d==n+1){
		if(x>=m) return 1;
		else return 0;
	}
	long long cnt=1,y=z,ans=0;
	while(cnt<=n){
		if(y%2==1){
			y/=2;
			cnt++;
			continue;
		}
		if(c[cnt]>d-1-x&&s[d]=='1') ans=(ans+dfs(d+1,x+1,z+pow(2,cnt-1)))%mod;
		else ans=(ans+dfs(d+1,x,z+pow(2,cnt-1)))%mod;
		y/=2;
		cnt++;
	}
	f[d][x][z]=ans;
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	printf("%lld",dfs(1,0,0));
	fclose(stdin);
	fclose(stdout);
	return 0;
}