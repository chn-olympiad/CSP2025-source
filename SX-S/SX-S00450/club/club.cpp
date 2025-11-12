#include<bits/stdc++.h>
#define int long long
using namespace std;
int _,n,cnt[3],ans;
struct node{
	int x,y,z;
}a[200005],ma[3][200005];
bool cmp0(node A,node B){
	return A.x-max(A.y,A.z)<B.x-max(B.y,B.z);
}
bool cmp1(node A,node B){
	return A.y-max(A.x,A.z)<B.y-max(B.x,B.z);
}
bool cmp2(node A,node B){
	return A.z-max(A.y,A.x)<B.z-max(B.y,B.x);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>_;
	while(_--){
		cin>>n;ans=0;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			int tmp=max(a[i].x,max(a[i].y,a[i].z));
			if(tmp==a[i].x) ma[0][++cnt[0]]=a[i];
			else if(tmp==a[i].y) ma[1][++cnt[1]]=a[i];
			else if(tmp==a[i].z) ma[2][++cnt[2]]=a[i];
			ans+=tmp;
		}
		if(cnt[0]>n/2){
			sort(ma[0]+1,ma[0]+cnt[0]+1,cmp0);
			for(int i=1;i<=cnt[0]-n/2;i++) ans-=ma[0][i].x-max(ma[0][i].y,ma[0][i].z);
		}
		else if(cnt[1]>n/2){
			sort(ma[1]+1,ma[1]+cnt[1]+1,cmp1);
			for(int i=1;i<=cnt[1]-n/2;i++) ans-=ma[1][i].y-max(ma[1][i].x,ma[1][i].z);
		}
		else if(cnt[2]>n/2){
			sort(ma[2]+1,ma[2]+cnt[2]+1,cmp2);
			for(int i=1;i<=cnt[2]-n/2;i++) ans-=ma[2][i].z-max(ma[2][i].y,ma[2][i].x);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
