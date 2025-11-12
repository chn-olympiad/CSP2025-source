#include<bits/stdc++.h>
using namespace std;
int T,n,a[4][100005],maxn;
int sum,num;
bool cmp(int x,int y) {
	return x>y;
}
void dfs(int k,int x,int y,int z) {
	if(k==n+1) {
		num=max(sum,num);
		return ;
	}
	if(x<maxn) {
		sum+=a[1][k];
		dfs(k+1,x+1,y,z);
		sum-=a[1][k];
	}
	if(y<maxn) {
		sum+=a[2][k];
		dfs(k+1,x,y+1,z);
		sum-=a[2][k];
	}
	if(z<maxn) {
		sum+=a[3][k];
		dfs(k+1,x,y,z+1);
		sum-=a[3][k];
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		sum=num=0;
		maxn=n/2;
		if(n>30) {
			sort(a[1]+1,a[1]+n+1,cmp);
			for(int i=1;i<=maxn;i++) {
				num+=a[1][i];
			}
			cout<<num<<endl;
			continue;
		}
		dfs(1,0,0,0);
		cout<<num<<endl;
	}
	return 0;
}
/**
zhelijurankeyiwansaolei
kepa xiangwan pabeizhua
**/
