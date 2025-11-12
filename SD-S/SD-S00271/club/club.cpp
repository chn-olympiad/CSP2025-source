#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=(int)1e5+10;
inline ll read(){
	ll x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(int)(c-'0');
		c=getchar();
	}
	return x*w;
}
inline void print(ll x){
	char s[20];
	int top=0;
	if(x==0){
		putchar('0');
		putchar('\n');
		return ;
	}
	if(x<0){
		x=-x;
		putchar('-');
	}
	while(x){
		top++;
		s[top]=(char)(x%10+'0');
		x/=10;
	}
	while(top){
		putchar(s[top]);
		top--;
	}
	putchar('\n');
}
int T;
int n,maxnum,anum,bnum,cnum,amax,bmax,cmax,maxnn;
int c[maxn][3];
ll ans;
int tot;
bool vis[maxn];
inline void dfs(ll cnt){
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=true;
		tot--;
		if(anum<maxnum){
			cnt+=c[i][0];
			anum++;
			dfs(cnt);
			anum--;
			cnt-=c[i][0];
		}
		if(bnum<maxnum){
			cnt+=c[i][1];
			bnum++;
			dfs(cnt);
			bnum--;
			cnt-=c[i][1];
		}
		if(cnum<maxnum){
			cnt+=c[i][2];
			cnum++;
			dfs(cnt);
			cnum--;
			cnt-=c[i][2];
		}
		tot++;
		vis[i]=false;
	}
	ans=max(ans,cnt);
}
inline bool cmp(int a,int b){
	return a>b;
}
int tem[maxn];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		maxnum=n>>1;
		ans=0;
		for(int i=1;i<=n;i++)vis[i]=0; 
		for(int i=1;i<=n;i++){
			c[i][0]=read();
			c[i][1]=read();
			c[i][2]=read();
			amax=max(amax,c[i][0]);
			bmax=max(bmax,c[i][1]);
			cmax=max(cmax,c[i][2]);
		}
		if(bmax==0&&cmax==0){
			ans=0;
			for(int i=1;i<=n;i++){
				tem[i]=c[i][0];
			}
			sort(tem+1,tem+n+1,cmp);
			for(int i=1;i<=maxnum;i++){
				ans+=tem[i];
			}
		}
		else{
			maxnn=max(amax,max(bmax,cmax));
			tot=n;
			dfs(0ll);
		}
		print(ans);
//		for(int i=1;i<=n;i++){
//			if(anum<maxnum){
//				dp[i][0]=mx(i)+c[i][0];
//				anum++;
//			}
//			if(bnum<maxnum){
//				dp[i][1]=mx(i)+c[i][1];
//				bnum++;
//			}
//			if(cnum<maxnum){
//				dp[i][2]=mx(i)+c[i][2];
//				cnum++;
//			}
//		}
//		print(mx(n+1));
//		for(int i=1;i<=n;i++){
//			int tem1,tem2,tem3;
//			cin>>tem1>>tem2>>tem3;
//			q.push(st(tem1,i,1));
//			q.push(st(tem2,i,2));
//			q.push(st(tem3,i,3));
//		}
//		while(q.size()){
//			st tem=q.top();
//			q.pop();
//			int a=tem.ap;
//						
//		}
//		for(int i=1;i<=n;i++){
//			a[i].id=i;
//			cin>>a[i].x>>a[i].y>>a[i].z;
//			b[i]=c[i]=a[i];
//		}
//		sort(a+1,a+n+1,cmp1);
//		sort(b+1,b+n+1,cmp2);
//		sort(c+1,c+n+1,cmp3);
	}
	fclose(stdin);
	fclose(stdout);
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
