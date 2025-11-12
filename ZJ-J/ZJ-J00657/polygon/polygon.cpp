#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+10;
const int mod=998244353;
int n,a[5010],f[5010],ans,g[5010][5010];
bool flag;
void init(){
	g[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			g[i][j]=g[i-1][j]+g[i-1][j-1];
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	sort(a+1,a+n+1);
	init();
	if(flag==0){
		int sum=0;
		for(int i=3;i<=n;i++){
			sum+=g[n][i];
			sum=(sum%mod+mod)%mod;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		f[0]=1;
		for(int j=1;j<=i;j++){
			for(int k=a[i];k>=a[j];k--){
				f[k]+=f[k-a[j]];
				f[k]=(f[k]%mod+mod)%mod;
			}
		}
		for(int k=a[i];k>=a[1];k--){
		//	cout<<f[k]<<endl;
			ans+=f[k];
			ans=(ans%mod+mod)%mod;
		}
//		ans+=f[a[i]];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=g[n][i];
		sum=(sum%mod+mod);
	}
	cout<<(sum-ans)%mod;
	
	return 0;
} 
