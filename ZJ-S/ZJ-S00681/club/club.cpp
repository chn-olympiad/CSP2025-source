#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int T,n,a[N][4],b[N],f[N],ans;
bool cmp(int a,int b){return a>b;}
void ljx(int x,int y,int z,int cnt){
	int l=0;
	for(int i=1;i<=n;i++)
		if(f[i]==x)
			b[++l]=max(a[i][y],a[i][z])-a[i][x];
	sort(b+1,b+1+l,cmp);
	for(int i=1;i<=cnt;i++)
		ans+=b[i];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		ans=0;
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			int m=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=m;
			if(m==a[i][1])f[i]=1,x++;
			else if(m==a[i][2])f[i]=2,y++;
			else f[i]=3,z++;
		}
		if(x>n/2)ljx(1,2,3,x-n/2);
		else if(y>n/2)ljx(2,1,3,y-n/2);
		else if(z>n/2)ljx(3,1,2,z-n/2);
		cout<<ans<<"\n";
	}
}