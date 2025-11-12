#include<cstdio>//40+24->64pts!
#include<algorithm>
#include<cstring>
using namespace std;
const int N=5010,MOD=998244353;
int arr[N];
int C[N][N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int ans=0;
	if(n<=21){
		for(int x=1;x<(1<<n);x++){
		int tot=0;
		int ma=-1;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(x&(1<<i)){
				cnt++;
					ma=max(ma,arr[i]);
					tot+=arr[i];
				}
			}
			if(cnt>=3){
				if(tot>ma*2) ans++;
				ans%=MOD; 
			}
		}
	}
	else{
		for(int i=0;i<=n;i++) C[0][i]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				C[i][j]=C[i-1][j-1]+C[i][j-1];
				C[i][j]%=MOD;
			}	
		}
		for(int i=3;i<=n;i++){
			ans+=C[i][n];
			ans%=MOD;
		}
	}
	printf("%d",ans);
	
	return 0;
}
