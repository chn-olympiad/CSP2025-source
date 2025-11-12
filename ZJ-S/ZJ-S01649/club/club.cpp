#include<bits/stdc++.h>
using namespace std;
char x;
int T,n,a[100005][3],f[2][105][105][105],b[100005],ans=0,ff=0,fff=0;
struct node{
	int a,b,v;
}c[100005];
bool cmp(node x,node y){
	return x.v>y.v;
}
char y;
void dfs(int x,int j,int k,int l,int v){
	if(x>n){
		ans=max(ans,v);
		return;
	}
	if(j<n/2)dfs(x+1,j+1,k,l,v+a[x][0]);
	if(k<n/2)dfs(x+1,j,k+1,l,v+a[x][1]);
	if(l<n/2)dfs(x+1,j,k,l+1,v+a[x][2]);
}
void solve1(){
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			b[i]=a[i][0];
			if(a[i][1]!=0||a[i][2]!=0)ff=1;
		}
		if(ff)dfs(1,0,0,0,0);
		else{
			sort(b+1,b+1+n);
//			int ans=0;
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
		}
		cout<<ans<<endl;
	}
}
void solve2(){
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			b[i]=a[i][0];
			if(a[i][1]!=0||a[i][2]!=0)ff=1;
			if(a[i][2]!=0)fff=1;
		}
		if((ff&&fff)||n<=200){
			for(int i=0;i<=1;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						for(int l=0;l<=n/2;l++){
							f[i][j][k][l]=0;
						}
					}
				}
			}
			ans=0;
			int p=0;
			for(int i=1;i<=n;i++){
				for(int j=min(i,n/2);j>=0;j--){
					for(int k=min(i,n/2);k>=0;k--){
						int l=i-j-k;
						if(l<0||l>i||l>n/2)continue;
						if(j!=0)f[p][j][k][l]=max(f[p^1][j-1][k][l]+a[i][0],f[p][j][k][l]);
						if(k!=0)f[p][j][k][l]=max(f[p^1][j][k-1][l]+a[i][1],f[p][j][k][l]);
						if(l!=0)f[p][j][k][l]=max(f[p^1][j][k][l-1]+a[i][2],f[p][j][k][l]);
						if(i==n)ans=max(ans,f[p][j][k][l]);
					}
				}
				p^=1;
			}
		}else if(!ff){
			sort(b+1,b+1+n);
			ans=0;
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
		}else if(!fff){
			ans=0;
			for(int i=1;i<=n;i++){
				c[i].a=a[i][0];
				c[i].b=a[i][1];
				c[i].v=c[i].a-c[i].b;
			}
			sort(c+1,c+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=c[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=c[i].b;
			}
		}
		cout<<ans<<endl;
	}
}
int main(){
//	cout<<&y-&x;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	solve2();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1*/