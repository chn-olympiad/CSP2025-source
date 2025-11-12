#include<bits/stdc++.h>
#define ll long long
#define lll __int128
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define ull unsigned long long
using namespace std;
const int N=1e6+145,P1=131,P2=13331;
const int P=998244353;

bool vis[N];
int n,m,c[N],way[N];
string s;
long long rans,dp[300005][20];// ״̬Ϊ i lst==j 

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    
    dp[0][0]=1;
    for(int i=0;i<(1<<n);i++){
    //	cout<<i<<"   ";
//		for(int j=0;j<=3;j++) cout<<dp[i][j]<<" ";
//		puts("");
    	
    	int sum=0;
    	for(int ty=0;ty<n;ty++) sum+=(i>>ty&1);
    	for(int ty=0;ty<n;ty++)
    	    if(!(i>>ty&1)){
    	    	for(int j=0;j<=sum;j++){
    	    		if(c[ty+1]<=j||s[sum]=='0') dp[i^(1<<ty)][j+1]=( dp[i^(1<<ty)][j+1]+dp[i][j] )%P;
    	    		else dp[i^(1<<ty)][j]=( dp[i^(1<<ty)][j]+dp[i][j] )%P;
				}
			}
	}
	for(int i=0;i<=n-m;i++)
	    rans=( rans+dp[(1<<n)-1][i] )%P;
	printf("%lld",rans);
	return 0;
}

