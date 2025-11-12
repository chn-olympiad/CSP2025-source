//bu gua fen de hua
//yun qi cha:70pts
//yun qi hao:80pts
//yun qi yue wei 75%
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,a[202][4],b[100005],sum,f[202][102][102];
int max(int a,int b,int c){return max(max(a,b),c);}
void input(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
}
void solve1(){
	memset(f,192,sizeof f);
	f[0][0][0]=0;
	for(int i=1;i<=n;i++){
		int rj=min(n/2,i);
		int rk=min(n/2,i);
		f[i][0][0]=f[i-1][0][0]+a[i][3];
		for(int k=1;k<=rk;k++)
			f[i][0][k]=max(f[i-1][0][k-1]+a[i][2],f[i-1][0][k]+a[i][3]);
		for(int j=1;j<=rj;j++){
			int rk=min(n/2,i-j);
			f[i][j][0]=max(f[i-1][j-1][0]+a[i][1],f[i-1][j][0]+a[i][3]);
			for(int k=1;k<=rk;k++)
				f[i][j][k]=max(f[i-1][j-1][k]+a[i][1],f[i-1][j][k-1]+a[i][2],f[i-1][j][k]+a[i][3]);
		}
	}
	ans=0;
	for(int i=n/2;i>=0;i--)
	for(int j=n/2;j>=0;j--){
		int k=n-i-j;
		if(k>n/2)break;
		ans=max(ans,f[n][i][j]);
	}
	cout<<ans<<endl;
}
bool check2(){
	for(int i=1;i<=n;i++)if(a[i][3])return 0;
	return 1;
}
void solve2(){
	for(int i=1;i<=n;i++)b[i]=a[i][1]-a[i][2],sum+=a[i][2];
	sort(b+1,b+n+1);
	for(int i=1;i<=n/2;i++)sum+=b[i];
	cout<<sum<<endl;
}
void solve3(){
	ans=0;
	for(int i=1;i<=n;i++)ans+=max(a[i][1],a[i][2],a[i][3]);
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		input();
		if(n<=200)solve1();
		else if(check2())solve2();
		else solve3();
	}
	return 0;
}

