#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=2e5+5;
const int inf=2e9+9999;
int n,a[N][3],ans,c[3],b[N];
inline int get(int o){
	int res=0;
	for(int i=1;i<=n;i++){
		res+=a[i][o],b[i]=-inf;
		for(int j=0;j<3;j++){
			if(j!=o) b[i]=max(b[i],a[i][j]-a[i][o]);
		}
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n/2;i++) res+=b[n-i+1];
	//printf("get:%d %d %d\n",o,res,b[n/2]);
	return res;
}
void sol(){
	scanf("%d",&n);ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	}
	c[0]=c[1]=c[2]=0;
	for(int i=1;i<=n;i++){
		int id=0;
		if(a[i][1]>a[i][id]) id=1;
		if(a[i][2]>a[i][id]) id=2;
		c[id]++,ans+=a[i][id];
	}
	if(c[0]<=n/2&&c[1]<=n/2&&c[2]<=n/2){
		printf("%d\n",ans);return;
	}
	ans=0;
	for(int o=0;o<3;o++) ans=max(ans,get(o));
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--) sol();
	return 0;
} 
