#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
struct node{
	int b[4],m,d,t;
}a[114514],d[114514];
bool cmp(node x,node y){
	return x.m>y.m;
}
bool cmp2(node x,node y){
	return x.d<y.d;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].b[1]>>a[i].b[2]>>a[i].b[3];
			a[i].m=0;
			a[i].t=1;
			int minn=114514,q=1;
			for(int j=1;j<=3;j++){
				if(a[i].b[j]>a[i].m){
					a[i].t=j;
					a[i].m=a[i].b[j];
				}
				if(a[i].b[j]<minn){
					minn=a[i].b[j];
					q=j;
				}
			}
			q=6-a[i].t-q;
			a[i].d=a[i].b[a[i].t]-a[i].b[q];
		}
		sort(a+1,a+n+1,cmp);
		int ans=0,c[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			ans+=a[i].b[a[i].t];
			c[a[i].t]++;
		}
		bool flg=1;
		int x=0;
		for(int i=1;i<=3;i++){
			if(c[i]>n/2){
				flg=0;
				x=i;
				break;
			}
		}
		if(flg){
			cout<<ans<<endl;
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i].t==x){
				d[++cnt]=a[i];
			}
		}
		sort(d+1,d+cnt+1,cmp2);
		for(int i=1;i<=cnt-n/2;i++){
			ans-=d[i].d;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//11.1 15:03
//code by K.S.
