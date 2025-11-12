#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt[15],ans[15],l1,l2,l3,ch;
struct node{
	int x,y,z,m,id;
}a[100005],b[100005],c[100005];
bool cmp(node x,node y){
	return x.m<y.m;
}
void solve(){
	cin>>n;
	ans[1]=ans[2]=ans[3]=0,l1=l2=l3=0;
	for(int i=1,x,y,z;i<=n;i++){
		cin>>x>>y>>z;
		if(x>=y&&x>=z)l1+=1,a[l1].x=x,a[l1].y=y,a[l1].z=z,a[l1].m=min(abs(x-y),abs(x-z)),ans[1]+=x;
		else if(y>=x&&y>=z)l2+=1,b[l2].x=x,b[l2].y=y,b[l2].z=z,b[l2].m=min(abs(y-x),abs(y-z)),ans[2]+=y;
		else if(z>=x&&z>=y)l3+=1,c[l3].x=x,c[l3].y=y,c[l3].z=z,c[l3].m=min(abs(z-x),abs(z-y)),ans[3]+=z;
	}
	if(l1<=n/2&&l2<=n/2&&l3<=n/2){
		cout<<ans[1]+ans[2]+ans[3]<<"\n";
		return;
	}
	if(l1>n/2){
		sort(a+1,a+l1+1,cmp);
		for(int i=1;i<=l1-n/2;i++)
		ans[1]-=a[i].m;
	}
	if(l2>n/2){
		sort(b+1,b+l2+1,cmp);
		for(int i=1;i<=l2-n/2;i++)
		ans[2]-=b[i].m;
	}
	if(l3>n/2){
		sort(c+1,c+l3+1,cmp);
		for(int i=1;i<=l3-n/2;i++)
		ans[3]-=c[i].m;
	}
	cout<<ans[1]+ans[2]+ans[3]<<"\n";
	return;
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
