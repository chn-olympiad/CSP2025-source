#include<bits/stdc++.h>
using namespace std;
int n,t,k,p,u,sum,xb;
struct node{
	int x,y,z;
}a[100005];
struct caoi{
	int l,r,md;
};
caoi d[100005],rr[100005],g[100005];
bool cmp(caoi aa,caoi bb){
	return aa.md<bb.md;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;k=0;u=0;p=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			sum+=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].x>a[i].y&&a[i].x>a[i].z){
				d[++p].l=a[i].x;
				d[p].r=i;
				d[p].md=min(a[i].x-a[i].y,a[i].x-a[i].z);
			}else if(a[i].y>a[i].x&&a[i].y>a[i].z){
				rr[++k].l=a[i].y;
				rr[k].r=i;
				rr[k].md=min(a[i].y-a[i].x,a[i].y-a[i].z);
			}else{
				g[++u].l=a[i].z;
				g[u].r=i;
				g[u].md=min(a[i].z-a[i].x,a[i].z-a[i].y);
			}
		}
		if(p<=n/2&&k<=n/2&&u<=n/2){
			cout<<sum<<'\n';
			continue;
		}
		if(p>n/2){
			xb=0;
			sort(d+1,d+1+p,cmp);
			while(p-xb>n/2){
				xb++;
				sum-=d[xb].md;
			}
		}else if(k>n/2){
			xb=0;
			sort(rr+1,rr+1+k,cmp);
			while(k-xb>n/2){
				xb++;
				sum-=rr[xb].md;
			}
		}else if(u>n/2){
			xb=0;
			sort(g+1,g+1+u,cmp);
			while(u-xb>n/2){
				xb++;
				sum-=g[xb].md;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}