#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=505,M=(1<<18),P=998244353;
int n,m,a[N],dp[19][M],ls[19][M],jc[N],ans;
char s[N];
void add(int &x,int y){
	x+=y;
	if(x>=P)x-=P;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jc[0]=1;
	for(int i=1;i<N;i++){
		jc[i]=1ll*jc[i-1]*i%P;
	}
	a[n+1]=P;
	cin>>n>>m;
	cin>>(s+1),dp[0][0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i-1);
	}
	sort(a,a+n);
	if(n<=18){
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int S=0;S<(1<<n);S++){
					if(!dp[j][S])continue;
					for(int k=0;k<n;k++){
						if((1<<k)&S)continue;
						if(i-1-j>=a[k]||s[i]=='0'){
							add(ls[j][S|(1<<k)],dp[j][S]);
						}else{
							add(ls[j+1][S|(1<<k)],dp[j][S]);
						}
					}
				}
			}
			for(int j=0;j<=n;j++){
				for(int S=0;S<(1<<n);S++){
					dp[j][S]=ls[j][S];
					ls[j][S]=0;
				}
			}
		}
		for(int j=m;j<=n;j++){
			for(int S=0;S<(1<<n);S++){
				add(ans,dp[j][S]);
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	cout<<jc[n]<<"\n";
	return 0;
}
