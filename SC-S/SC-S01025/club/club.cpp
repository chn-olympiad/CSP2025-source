#include<bits/stdc++.h>
using namespace std;
int t,n,a[100003][4]={0},xq[100003]={0},yq[100003]={0},zq[100003]={0};
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--&&cin>>n){
		int x=0,y=0,z=0,xm=0,ym=0,zm=0,ans=0;
		for(int i=1;i<=n&&cin>>a[i][1]>>a[i][2]>>a[i][3];i++){//aj[i]为最小的差 
			int maxn=max(max(a[i][1],a[i][2]),a[i][3]);
			if(maxn==a[i][1]){//1最大 
				x++,xq[++xm]=a[i][1]-max(a[i][2],a[i][3]);
			}else if(a[i][2]>a[i][3]){//2最大 
				y++,yq[++ym]=a[i][2]-max(a[i][1],a[i][3]);
			}else{//3最大 
				z++,zq[++zm]=a[i][3]-max(a[i][1],a[i][2]);
			}
			ans+=maxn;
		}
		//cout<<x<<y<<z<<" ans="<<ans<<"\n";
		sort(xq+1,xq+xm+1);
		sort(yq+1,yq+ym+1);
		sort(zq+1,zq+zm+1);//每一个社团的最小差值 
		//for(int i=0;i<=ym;i++)cout<<"第"<<i<<"个最小差值"<<yq[i]<<"\n";
		int generall;
		if(x>n/2){
			generall=x-n/2;
			for(int i=1;i<=generall;i++)ans-=xq[i];
		}else if(y>n/2){
			generall=y-n/2;
			for(int i=1;i<=generall;i++)ans-=yq[i];
		}else if(z>n/2){
			generall=z-n/2;
			for(int i=1;i<=generall;i++)ans-=zq[i];
		}
		cout<<ans;if(t>0)cout<<"\n";
	}
	return 0;
}