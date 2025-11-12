#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
int T,n,a[N][4],num[4],maxx=0;
void dfs(int id,int f1,int f2,int f3,int val){
	if(id==n){
		maxx=max(maxx,val);
		return;
	}
	if(f1<n/2)
	dfs(id+1,f1+1,f2,f3,val+a[id+1][1]);
	if(f2<n/2)
	dfs(id+1,f1,f2+1,f3,val+a[id+1][2]);
	if(f3<n/2)
	dfs(id+1,f1,f2,f3+1,val+a[id+1][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;maxx=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		dfs(0,0,0,0,0);
		printf("%d\n",maxx);
	}
	return 0;
}
