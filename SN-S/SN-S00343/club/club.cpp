//李承恩 SN-S00343 西安湖滨中学
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][4],h[4][N],siz[4];
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)cin>>a[i][j];
	long long ans=0;
	siz[1]=siz[2]=siz[3]=0;
	for(int i=1;i<=n;i++){
		int p1=0,p2=0;
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			p1=1;
			if(a[i][2]>a[i][3])p2=2;
			else p2=3;
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			p1=2;
			if(a[i][1]>a[i][3])p2=1;
			else p2=3;
		}
		else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
			p1=3;
			if(a[i][1]>a[i][2])p2=1;
			else p2=2;
		}
		ans+=a[i][p1];
		siz[p1]++;
		h[p1][siz[p1]]=a[i][p1]-a[i][p2];
	}
	int p=0;
	for(int j=1;j<=3;j++)if(siz[j]>n/2)p=j;
	if(p){
		sort(h[p]+1,h[p]+1+siz[p],cmp);
		while(siz[p]>n/2)ans-=h[p][siz[p]],siz[p]--;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}
