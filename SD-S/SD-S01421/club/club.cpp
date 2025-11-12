#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
struct node{
	int x,y,z;
	int ma;
}a[N];
bool cmp(node a,node b){
	return a.x>a.y;
}
bool cmpp(node a,node b){
	return a.ma>b.ma;
}
void solve(){ 
	memset(a,0,sizeof(a));
	int n;
	cin>>n;
	int f=1;
	for(int i=1;i<=n;i++){
		int xx,yy,zz;
		int maxx=-1;
		cin>>xx>>yy>>zz;
		maxx=max({xx,yy,zz});
		a[i]={xx,yy,zz,maxx};
		if(yy>0){
			f=0;
		}
	}
	if(f==1){
		int sum=0;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			sum+=a[i].x; 
		}
		cout<<sum<<"\n";
		return ;
	}
	if(f==0){
		int sum=0;
		int xx=0,yy=0;
		sort(a+1,a+1+n,cmpp);
		for(int i=1;i<=n;i++){
			if((yy==n/2&&xx<n/2)||(a[i].x>a[i].y&&xx<n/2)){
				xx++;
				sum+=a[i].x;
			}else if((xx==n/2&&yy<n/2)||(a[i].x<a[i].y&&yy<n/2)){
				yy++;
				sum+=a[i].y;
			}
		}
		cout<<sum<<"\n";
		return;
	
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}

	return 0;
}

