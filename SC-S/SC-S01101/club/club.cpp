#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n;
struct node{
	int x,y,z;
}a[100010];
bool cmp_A(node x,node y){
	return x.x>=y.x;
}
bool cmp_B(node x,node y){
	return x.y-x.x>y.y-y.x;
}
bool is_A(){
	for(int i=1;i<=n;i++){
		if(a[i].y!=0||a[i].z!=0){
			return 0;
		}
	}
	return 1;
}
int A(){
	sort(a+1,a+1+n,cmp_A);
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=a[i].x;
	}
	return ans;
}
bool is_B(){
	for(int i=1;i<=n;i++){
		if(a[i].z!=0){
			return 0;
		}
	}
	return 1;
}
int B(){
	sort(a+1,a+1+n,cmp_B);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i].x;
	}
	for(int i=1;i<=n/2;i++){
		ans+=a[i].y-a[i].x;
	}
	return ans;
}
int f[210][110][101];
int DP(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				f[i][j][k]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(j-1>=0) f[i][j][k]=f[i-1][j-1][k]+a[i].x;
				if(k-1>=0) f[i][j][k]=max(f[i-1][j][k-1]+a[i].y,f[i][j][k]);
				if(i-j-k-1>=0) f[i][j][k]=max(f[i-1][j][k]+a[i].z,f[i][j][k]);
				//cout<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k]<<endl;
			//cout<<f[i][j][k]<<' ';
			}
			//cout<<endl;
		}
		//cout<<endl;
	}
	int maxx=0;
	for(int i=0;i<=n/2;i++){
		for(int j=n/2-i;j<=n/2;j++){
			maxx=max(maxx,f[n][i][j]);
		}
	}
	return maxx;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		bool f=0;
		if(is_A()){
			f=1;
			cout<<A()<<'\n';
		}
		if(!f&&is_B()){
			f=1;
			cout<<B()<<'\n';
		}
		if(!f&&n<=200){
			f=1;
			cout<<DP()<<'\n';
		}
	}
	return 0;
}