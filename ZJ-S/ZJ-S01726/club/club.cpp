#include <bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,z;
}a[100010];
int t,n;
int cnt[5][100010],xx,yy,zz;
long long temp[100010],ans;
inline void init(){
	ans=0;xx=0;yy=0;zz=0;
	for (int i=1;i<=n;++i){
		temp[i]=0;
		cnt[1][i]=cnt[2][i]=cnt[3][i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		init();
		cin>>n;
		for (int i=1;i<=n;++i){
			cin>>a[i].x>>a[i].y>>a[i].z;
			ans+=max(max(a[i].x,a[i].y),a[i].z);
			if (a[i].x>=a[i].y&&a[i].x>=a[i].z) cnt[1][++xx]=i;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) cnt[2][++yy]=i;
			else if (a[i].z>=a[i].x&&a[i].z>=a[i].y) cnt[3][++zz]=i;
		}
		if (xx>n/2){
			for (int i=1;i<=xx;++i) temp[i]=a[cnt[1][i]].x-max(a[cnt[1][i]].y,a[cnt[1][i]].z);
			sort(temp+1,temp+xx+1);
			for (int i=1;i<=xx-n/2;++i) ans-=temp[i];
		}
		else if (yy>n/2){
			for (int i=1;i<=yy;++i) temp[i]=a[cnt[2][i]].y-max(a[cnt[2][i]].x,a[cnt[2][i]].z);
			sort(temp+1,temp+yy+1);
			for (int i=1;i<=yy-n/2;++i) ans-=temp[i];
		}
		else if (zz>n/2){
			for (int i=1;i<=zz;++i) temp[i]=a[cnt[3][i]].z-max(a[cnt[3][i]].y,a[cnt[3][i]].x);
			sort(temp+1,temp+zz+1);
			for (int i=1;i<=zz-n/2;++i) ans-=temp[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
