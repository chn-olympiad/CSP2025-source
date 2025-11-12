#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100+10;
ll n,m,k,a[maxn],aa[maxn][maxn],b[maxn][maxn],ans[maxn][maxn],cnt;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lld",&a[++cnt]);
	k=a[1];
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			aa[i][j]=a[(i-1)*n+j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j]=aa[j][i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j%2==0) ans[i][j]=b[n-i+1][j];
			else ans[i][j]=b[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==k){
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	return 0;
}
