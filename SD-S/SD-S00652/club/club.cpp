#include<iostream>
#include<cstdio> 
using namespace std;
const int N=205,M=1e5+5;
long long f[N][N][N],ans;
int n,T;
struct per{
	int a1,a2,a3;
	int p1,p2,p3;
	void init(){
		if(a1>=a2&&a2>=a3)p1=a1,p2=a2,p3=a3;
		if(a3>=a2&&a2>=a1)p1=a3,p2=a2,p3=a1;
		if(a2>=a1&&a1>=a3)p1=a2,p2=a1,p3=a3;
		if(a3>=a1&&a1>=a2)p1=a3,p2=a1,p3=a2;
		if(a1>=a3&&a3>=a2)p1=a1,p2=a3,p3=a2;
		if(a2>=a3&&a3>=a1)p1=a2,p2=a3,p3=a1;
	}
}a[M];
bool cmp(per a,per b){
	return a.a1>a.a2;
}
void work(){
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n/2;i++)ans+=a[i].a1;
	printf("%lld\n",ans);
	return ;
}
void sol(){
	bool flg=1;
	ans=0;
	scanf("%d",&n);
	int st=n/2;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
		if(a[i].a2||a[i].a3)flg=0;
	}
	if(flg){
		work();
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(i,st);j++){
			for(int k=0;k<=min(i-j,st);k++){
				f[i][j][k]=0;
				int p=i-j-k;
				if(p>st)continue;
				if(j!=0)f[i][j][k]=max(f[i-1][j-1][k]+a[i].a1,f[i][j][k]);
				if(k!=0)f[i][j][k]=max(f[i-1][j][k-1]+a[i].a2,f[i][j][k]);
				if(p!=0)f[i][j][k]=max(f[i-1][j][k]+a[i].a3,f[i][j][k]);
				if(i==n)ans=max(ans,f[i][j][k]);
				//cout<<i<<" "<<j<<" "<<k<<" "<<p<<":"<<f[i][j][k]<<"\n";
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		sol();
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
