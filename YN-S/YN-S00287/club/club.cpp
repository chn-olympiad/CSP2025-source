#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+6;
ll max(const ll aaa,const ll bbb){
	return aaa>bbb?aaa:bbb;
}
struct node{
	int x,y,z;
}a[N];
//bool b[N];
ll ans;
int n,t;
void dfs1(int t,ll flag,int tong1,int tong2,int tong3){
	if(t == (n+1)){
		ans = max(ans,flag);
		return;
	}
	if(tong1<(n>>1)){
		dfs1(t+1,flag+a[t].x,tong1+1,tong2,tong3);
	}
	if(tong2<(n>>1)){
		dfs1(t+1,flag+a[t].y,tong1,tong2+1,tong3);
	}
	if(tong3<(n>>1)){
		dfs1(t+1,flag+a[t].z,tong1,tong2,tong3+1);
	}
}
bool cmp1(const node aaa,const node bbb){
	return aaa.x>bbb.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		bool flag = true;
		for(int i = 1;i<=n;i++){
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y != 0 || a[i].z!=0) flag = false;
		}
		if(!flag){
			ans=0;
			dfs1(1,0,0,0,0);
		}else{
			ans=0;
			sort(a+1,a+n+1,cmp1);
			for(int i = 1;i<=(n>>1);i++)ans+=a[i].x;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
