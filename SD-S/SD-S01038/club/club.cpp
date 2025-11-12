#include<bits/stdc++.h>
using namespace std;
long long n,maxx=0,xx,yy,zz;
struct stu{
	long long x,y,z;
}a[100010];
void dfs(long long dx,long long sum){
	if(dx==n){
		if(maxx<sum){
			maxx=sum;
		}
		return;
	}
	if(xx+1<=n/2){
		xx++;
		dfs(dx+1,sum+a[dx].x);
		xx--;
	}
	if(yy+1<=n/2){
		yy++;
		dfs(dx+1,sum+a[dx].y);
		yy--;
	}
	if(zz+1<=n/2){
		zz++;
		dfs(dx+1,sum+a[dx].z);
		zz--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		maxx=0;
		xx=0;
		yy=0;
		zz=0;
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		}
		dfs(0,0);
		cout<<maxx<<endl;
	}
	return 0;
}
