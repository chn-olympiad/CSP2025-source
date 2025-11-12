#include<bits/stdc++.h>
using namespace std;
const int N=250,M=1e5+100;
int n;
int a[M][5];
unsigned f[N][N>>1][N>>1];
unsigned ans;
void solve1(){
	ans=0;
	for(int i=1;i<=n;++i){
		for(int x=0;x<=(n>>1)&&x<=i;++x){
			for(int y=max(0,i-x-(n>>1));y<=(n>>1)&&y<=i;++y){
				int z=i-x-y;
				f[i][x][y]=0;
				if(x>=1) f[i][x][y]=max(f[i][x][y],f[i-1][x-1][y]+a[i][1]);
				if(y>=1) f[i][x][y]=max(f[i][x][y],f[i-1][x][y-1]+a[i][2]);
				if(z>=1) f[i][x][y]=max(f[i][x][y],f[i-1][x][y]+a[i][3]);
			}
		}
	}
	for(int x=0;x<=(n>>1);++x){
		for(int y=(n>>1)-x;y<=(n>>1);++y){
			ans=max(ans,f[n][x][y]);
		}
	}
	cout<<ans<<"\n";
}
int b[N];
void solveA(){
	ans=0;
	for(int i=1;i<=n;i++) b[i]=a[i][1];
	sort(b+1,b+1+n,greater<int>());
	for(int i=1;i<=(n>>1);i++) ans+=b[i];
	cout<<ans<<"\n";
}
struct ar{
	int peo,val,d;
}c[M*3];int top;
struct cmp_val{
	bool operator() (ar A,ar B){
		return A.val>B.val;
	}
};
int cnt[5];bool vis[M];
void solve2(){
	top=0;unsigned ans2=0;
	cnt[1]=0,cnt[2]=0,cnt[3]=0;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		++top;c[top]=(ar){i,a[i][1],1};
		++top;c[top]=(ar){i,a[i][2],2};
		++top;c[top]=(ar){i,a[i][3],3};
	}
	sort(c+1,c+1+top,cmp_val());
	for(int i=1;i<=top;i++){
		if(cnt[c[i].d]<(n>>1)&&!vis[c[i].peo]){
			vis[c[i].peo]=1;
			cnt[c[i].d]++;
			ans2+=c[i].val;
		}
	}
	cout<<ans2<<"\n";
}
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		bool flgA=1,flgB=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0) flgA=0;
			if(a[i][3]!=0) flgA=0,flgB=0;
		}
		if(n<=370) solve1();
		else if(flgA) solveA();
		else solve2();
	}
	return 0;
}

