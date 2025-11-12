#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MX=1e5+10;
int n,fb[MX][2]; 
struct node{
	int x,y,z;
}a[MX];
ll ans=0;
bool cmpa(node p,node q){
	return p.x>q.x;
}
bool cmpb(node p,node q){
	if(p.x==q.x)return p.y>q.y;
	return p.x>q.x;
}
void mian(){ 
	ans=0;
	sort(a+1,a+n+1,cmpa); 
	for(int i=1;i<=(n>>1);i++){
		ans+=1LL*a[i].x;
	}
	printf("%lld\n",ans);
	return ;
}
void dfs(int now,ll sum,int wa,int wb){
	if(now==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(wa+1<=n/2){
		dfs(now+1,sum+a[now].x,wa+1,wb);
	}
	if(wb+1<=n/2){
		dfs(now+1,sum+a[now].y,wa,wb+1);
	}
	return ;
}
void dfsa(int now,ll sum,int wa,int wb,int wc){
	if(now==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(wa+1<=n/2){
		dfsa(now+1,sum+a[now].x,wa+1,wb,wc);
	}
	if(wb+1<=n/2){
		dfsa(now+1,sum+a[now].y,wa,wb+1,wc);
	}
	if(wc+1<=n/2){
		dfsa(now+1,sum+a[now].z,wa,wb,wc+1);
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		int fa=1,fb=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y!=0)fa=0;
			if(a[i].z!=0)fb=0;
		}
		if(fa && fb){
			mian();//特殊性质A 
		}
		ans=0;
		if(!fa && fb)dfs(1,0,0,0);
		if(!fa && !fb)dfsa(1,0,0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
luogu:790382

ccf就不能出的和去年一个难度吗，我还能做出来前两题 

今年第一题怎么这么猎奇，是绿吧 

完了我特殊性质B都没写出来啊

左边的大哥半个小时过了 
 
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
