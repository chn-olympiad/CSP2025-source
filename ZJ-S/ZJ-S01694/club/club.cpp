#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
struct node{
	int x[5],t[5];
}a[1000005];
bool cmp1(int x,int y){
	return x>y;
}
void getval(int idx){
	int u[5];
	for(int i=1;i<=3;i++)u[i]=a[idx].x[i];
	sort(u+1,u+3+1,cmp1);
	for(int i=1;i<=3;i++)
	if(u[1]==a[idx].x[i])a[idx].t[1]=i;
	for(int i=1;i<=3;i++)
	if(u[2]==a[idx].x[i]&&i!=a[idx].t[1])a[idx].t[2]=i;
	for(int i=1;i<=3;i++)
	if(u[2]==a[idx].x[i]&&i!=a[idx].t[1]&&i!=a[idx].t[2])a[idx].t[3]=i;
	return;
}
bool cmp(node a,node b){
	int x=a.x[a.t[1]]-a.x[a.t[2]];
	int y=b.x[b.t[1]]-b.x[b.t[2]];
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
			getval(i);
		}
		sort(a+1,a+n+1,cmp);
		int sum[5]={},ans=0;
		for(int i=1;i<=n;i++){
			int x=sum[a[i].t[1]],y=sum[a[i].t[2]],z=sum[a[i].t[3]];
			int X=a[i].x[a[i].t[1]],Y=a[i].x[a[i].t[2]],Z=a[i].x[a[i].t[2]];
			if(X==Y){
				if(x==n/2&&y==n/2)
					sum[a[i].t[3]]++,
					ans+=Z;
				else if(x<=y)
					sum[a[i].t[1]]++,
					ans+=X;
				else
					sum[a[i].t[2]]++,
					ans+=Y;
			} else if(Y==Z){
				if(x==n/2)
					if(y<=z){
						sum[a[i].t[2]]++;
						ans+=Y;
					} else {
						sum[a[i].t[3]]++;
						ans+=Z;
					}
				else{
					sum[a[i].t[1]]++;
					ans+=X;
				}
			} else {
				if(x<=n/2)
					sum[a[i].t[1]]++,
					ans+=X;
				else if(y<=n/2)
					sum[a[i].t[2]]++,
					ans+=Y;
				else
					sum[a[i].t[3]]++,
					ans+=Z;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
