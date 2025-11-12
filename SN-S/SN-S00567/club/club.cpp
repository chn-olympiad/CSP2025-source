#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,a[N][3],c,v[3],p[N],b[N],m;
ll ans;
void sol(){
	cin>>n;
	v[0]=v[1]=v[2]=ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++)
			scanf("%d",&a[i][j]);
		if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]) ans+=a[i][0],v[0]++,p[i]=0;
		else if(a[i][1]>a[i][2]) ans+=a[i][1],v[1]++,p[i]=1;
		else ans+=a[i][2],v[2]++,p[i]=2;
	}
	c=-1;
	if(v[0]>n/2) c=0;
	else if(v[1]>n/2) c=1;
	else c=2;
	if(c<0){printf("%lld\n",ans);return;}
	m=0;
	for(int i=1;i<=n;i++) if(p[i]==c) b[++m]=max(a[i][c==0?1:0],a[i][c==2?1:2])-a[i][c];
	sort(b+1,b+m+1);
	for(int i=m;i>m-(v[c]-n/2);i--) ans+=b[i];
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ii();
	int TT;for(scanf("%d",&TT);TT--;)
	sol();
	return 0;
}
