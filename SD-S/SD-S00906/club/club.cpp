#include<bits/stdc++.h>
using namespace std;
int n,t,a[100010][4],sum;
struct point{
	int x,y;
}xh[100010];
bool ff(point aa,point bb){
	return aa.y>bb.y;
}
int nn;
void dg(int xb,int f1,int f2,int f3,int ans){
	if(xb==n+1){
		sum=max(sum,ans);
		return ;
	}
	if(f1<nn){
		dg(xb+1,f1+1,f2,f3,ans+a[xb][1]);
	}
	if(f2<nn){
		dg(xb+1,f1,f2+1,f3,ans+a[xb][2]);
	}
	if(f3<nn){
		dg(xb+1,f1,f2,f3+1,ans+a[xb][3]);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		nn=n/2;
		for(int i=1;i<=n;i++){
			a[i][1]=a[i][2]=a[i][3]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			xh[i].x=i;
			xh[i].y=max(a[i][1],max(a[i][2],a[i][3]));
		}
		if(n<=10){
			sum=0;
			dg(1,0,0,0,0);
			cout<<sum<<'\n';
			continue;
		}
		sort(xh+1,xh+1+n,ff);
		int aa[4];aa[1]=aa[2]=aa[3]=0;int ans=0;
		for(int i=1;i<=n;i++){
			int f1=0,f2=0,f3=0;
			if(a[xh[i].x][1]>=a[xh[i].x][2]&&a[xh[i].x][1]>=a[xh[i].x][3]){
				f1=1;
				if(a[xh[i].x][2]>=a[xh[i].x][3]){
					f2=2;f3=3;
				}else{f2=3;f3=2;}
			}else if(a[xh[i].x][2]>=a[xh[i].x][1]&&a[xh[i].x][2]>=a[xh[i].x][3]){
				f1=2;
				if(a[xh[i].x][1]>=a[xh[i].x][3]){
					f2=1;f3=3;
				}else{f2=3;f3=1;}
			}else if(a[xh[i].x][3]>=a[xh[i].x][2]&&a[xh[i].x][3]>=a[xh[i].x][1]){
				f1=3;
				if(a[xh[i].x][1]>=a[xh[i].x][2]){
					f2=1;f3=2;
					}else{f2=2;f3=1;}
			}
			if(aa[f1]<(n/2)){
				ans+=a[xh[i].x][f1];
				aa[f1]++;
			}else if(aa[f2]<(n/2)){
				ans+=a[xh[i].x][f2];
				aa[f2]++;
			}else{
				ans+=a[xh[i].x][f3];
				aa[f3]++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


