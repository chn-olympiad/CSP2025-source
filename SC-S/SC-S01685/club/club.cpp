#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int T,n;
struct member{
	int d1,d2,d3,mxd;
}a[N];

int k;
bool vis[N];
int mx;
void dfs(int d1,int d2,int d3,int sum){
	int i,j;
	if(d1+d2+d3==n){
		mx=max(mx,sum);
		return ;
	}
	for(i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(d1<k)dfs(d1+1,d2,d3,sum+a[i].d1);
			if(d2<k)dfs(d1,d2+1,d3,sum+a[i].d2);
			if(d3<k)dfs(d1,d2,d3+1,sum+a[i].d3);
			vis[i]=0;
		}
	}
	
}

void func(){
	int i;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i].d1>>a[i].d2>>a[i].d3;
	k=n/2;
	dfs(0,0,0,0);
	cout<<mx<<endl;
	mx=0;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) func();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 