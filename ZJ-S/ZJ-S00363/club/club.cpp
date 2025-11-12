#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int x,y,z,flag;
	int maxn;
}q[N];
int n;
bool cmp(node a,node b){
	return a.maxn>b.maxn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long ans=0;
	int T=0;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].z);
		}
		int d1=0,d2=0,d3=0;
		for(int i=1;i<=n;i++){
			int a=q[i].x,b=q[i].y,c=q[i].z;
			if(a>=b && a>=c){
				d1++;
				ans+=a;
				q[i].flag=1;
			}
			else if(b>=a && b>=c){
				d2++;
				ans+=b;
				q[i].flag=2;
			}
			else if(c>=b && c>=a){
				d3++;
				ans+=c;
				q[i].flag=3;
			}
		}
		if(d1*2<=n && d2*2<=n && d3*2<=n){
			cout<<ans<<endl;
		}
		else if(d1*2>n){
			for(int i=1;i<=n;i++){
				if(q[i].flag==1){
					q[i].maxn=max(q[i].y-q[i].x,q[i].z-q[i].x);
				}
			}
			sort(q+1,q+n+1,cmp);
			int cnt=0;
			for(int i=1;i<=n && (d1-cnt)*2>n;i++){
				if(q[i].flag==1){
					ans+=q[i].maxn;
					cnt++;
				}
				if(d1-cnt<=n/2) break;
			}
			cout<<ans<<endl;
		}
		else if(d2*2>n){
			for(int i=1;i<=n;i++){
				if(q[i].flag==2){
					q[i].maxn=max(q[i].x-q[i].y,q[i].z-q[i].y);
				}
			}
			sort(q+1,q+n+1,cmp);
			int cnt=0;
			for(int i=1;i<=n && (d2-cnt)*2>n;i++){
				if(q[i].flag==2){
					ans+=q[i].maxn;
					cnt++;
				}
				if(d2-cnt<=n/2) break;
			}
			cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				if(q[i].flag==3){
					q[i].maxn=max(q[i].y-q[i].z,q[i].x-q[i].z);
				}
			}
			sort(q+1,q+n+1,cmp);
			int cnt=0;
			for(int i=1;i<=n && (d3-cnt)*2>n;i++){
				if(q[i].flag==3){
					ans+=q[i].maxn;
					cnt++;
				}
				if(d3-cnt<=n/2) break;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
