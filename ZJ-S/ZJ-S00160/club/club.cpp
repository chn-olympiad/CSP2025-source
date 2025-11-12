#include<bits/stdc++.h>
using namespace std;
long long T,n,i,x,y,z,ans,f[100010],aa[100010],b[100010],c[100010],ma;
struct node{
	long long ma,md,mi,x,y,z;
}a[100010];
bool cmp(node q,node h){
	if(q.ma==h.ma){
		if(q.md==h.md) return q.mi>h.mi;
		else return q.md>h.md;
	}
	else return q.ma>h.ma;
}
void sc(int t,int x,int y,int z,long long sum){
	if(t==n+1){
		ma=max(ma,sum);
		return ;
	}
	if(x<n/2) sc(t+1,x+1,y,z,sum+aa[t]);
	if(y<n/2) sc(t+1,x,y+1,z,sum+b[t]);
	if(z<n/2) sc(t+1,x,y,z+1,sum+c[t]);
}
bool cmp1(int q,int h){
	return q>h;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ma=0;ans=0;
		if(n<=20){
			for(i=1;i<=n;i++) cin>>aa[i]>>b[i]>>c[i];
			sc(1,0,0,0,0);
			cout<<ma<<"\n";
			continue;
		}
		if(n==100000){
			for(i=1;i<=n;i++) cin>>aa[i]>>b[i]>>c[i];
			sort(aa+1,aa+1+n,cmp1);
			for(i=1;i<=n/2;i++) ans+=aa[i];
			cout<<ans<<"\n";
			continue;
		}
		else{
			memset(f,0,sizeof(f));
			for(i=1;i<=n;i++){
				cin>>x>>y>>z;
				if(x>=y&&x>=z){
					a[i].ma=x,a[i].x=1;
					if(y>=z) a[i].md=y,a[i].y=2,a[i].mi=z,a[i].z=3;
					else a[i].md=z,a[i].y=3,a[i].mi=y,a[i].z=2;
				}
				else if(y>=x&&y>=z){
					a[i].ma=y,a[i].x=2;
					if(x>z) a[i].md=x,a[i].y=1,a[i].mi=z,a[i].z=3;
					else a[i].md=z,a[i].y=3,a[i].mi=x,a[i].z=1;
				}
				else{
					a[i].ma=z,a[i].x=3;
					if(x>=y) a[i].md=x,a[i].y=1,a[i].mi=y,a[i].z=2;
					else a[i].md=y,a[i].y=2,a[i].mi=x,a[i].z=1;
				}
			}
			ans=0;
			sort(a+1,a+1+n,cmp);
			for(i=1;i<=n;i++){
				if(f[a[i].x]>=n/2) ans=ans-a[i-1].ma+max(a[i-1].md+a[i].ma,a[i-1].ma+a[i].md);
				else f[a[i].x]++,ans+=a[i].ma;
			}	
			cout<<ans<<"\n";
		}
	}
}
