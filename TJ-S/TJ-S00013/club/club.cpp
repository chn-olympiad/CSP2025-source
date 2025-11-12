#include<cstdio>
#include<algorithm>
int t;
int n;
const int MAXN=100012,MAXS=MAXN*20000;
long long mem[MAXN][MAXS];
bool hasmem[MAXN][MAXS];
int s[5][MAXN];
int c[10];
long long dfs(int m,long long sum){
	if(m==n){
		return sum;
	}
	if(hasmem[m][sum])return mem[m][sum];
	int t1=0,t2=0,t3=0;
	c[1]++;
	if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2)t1=dfs(m+1,sum+s[1][m+1]);
	c[1]--;
	
	c[2]++;
	if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2)t2=dfs(m+1,sum+s[2][m+1]);
	c[2]--;
	
	c[3]++;
	if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2)t3=dfs(m+1,sum+s[3][m+1]);
	c[3]--;
	
	t1=std::max(t1,t2);
	t1=std::max(t1,t3);
	hasmem[m][sum]=true;
	mem[m][sum]=t1;
	return t1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&s[1][i],&s[2][i],&s[3][i]);
		printf("%lld\n",dfs(0,0));
		for(int i=1;i<=10;i++)c[i]=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++)s[i][j]=0;
		}
	}
	return 0;
}
