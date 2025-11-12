#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],b[N],m[4],s,ans;
int nax(int k){return max(max(a[k][1],a[k][2]),a[k][3]);}
int nin(int k){return min(min(a[k][1],a[k][2]),a[k][3]);}
int nid(int k){return a[k][1]+a[k][2]+a[k][3]-nax(k)-nin(k);}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;s=0;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(m,0,sizeof(m));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int maxx=nax(i),midd=nid(i);
			b[i]=maxx-midd;
			ans+=maxx;
			for(int j=1;j<=3;j++){
				if(maxx==a[i][j])m[j]++;
				if(m[j]>s)s=m[j];
			}
		}
		sort(b+1,b+n+1);
		for(int i=1;i<=s-n/2;i++)ans-=b[i];
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}