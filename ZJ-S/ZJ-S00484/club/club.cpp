#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;i++)
#define UF(i,a,b) for(int i=a;i>=b;i--)
#define look_memory cerr<<abs(&M2-&M1)/1024.0/1024<<'\n'
#define look_time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<'\n'
using namespace std;
#define LL long long
bool M1;
const int N=1e5+100;
int n,res;
int a[N][5],sz[5];
void dfs(int bh,int gs,int sum){
	if(bh==n+1){
		res=max(res,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(sz[i]+1<=n/2){
			sz[i]++;
			dfs(bh+1,i,sum+a[bh][i]);
			sz[i]--;
		}
	}
}
void Sub_A(){
	memset(sz,0,sizeof(sz));
	res=0;
	for(int i=1;i<=3;i++){
		dfs(1,i,0);
	}
	cout<<res<<'\n';
}
void Sub_B(){
	int yyx[N];
	for(int i=1;i<=n;i++) yyx[i]=a[i][1];
	sort(yyx+1,yyx+n+1);
	res=0;
	for(int i=n;i>n/2;i--) res+=yyx[i];
	cout<<res<<'\n';
}
struct node{
	int cha,bh;
}xth[N];
bool cmp(node x,node y){
	return x.cha>y.cha;
}
void Sub_C(){
	for(int i=1;i<=n;i++){
		xth[i].cha=a[i][2]-a[i][1];
		xth[i].bh=i;
	}
	res=0;
	sort(xth+1,xth+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(i<=n/2){
			res+=a[xth[i].bh][2];
		}else{
			res+=a[xth[i].bh][1];
		}
	}
	cout<<res<<'\n';
}
namespace Sub_D{
	struct Node{
		int gs,bh,cha;
	}xy[N*3];
	bool Cmp(Node x,Node y){
		return x.cha>y.cha;
	}
	int cnt,res;
	int vis[N],sz[5];
	void solve_D(){
		cnt=res=0;
		for(int i=1;i<=n;i++){
			xy[cnt+1].gs=1;
			xy[cnt+1].bh=i;
			xy[cnt+1].cha=0;
			xy[cnt+2].gs=2;
			xy[cnt+2].bh=i;
			xy[cnt+2].cha=a[i][2]-a[i][1];
			xy[cnt+3].gs=3;
			xy[cnt+3].bh=i;
			xy[cnt+3].cha=a[i][3]-a[i][1];
			cnt+=3;
		}
		memset(vis,0,sizeof(vis));
		memset(sz,0,sizeof(sz));
		sort(xy+1,xy+cnt+1,Cmp);
		int pos=-1,num=0;
		for(int i=1;i<=cnt;i++){
			if(xy[i].cha>0){
				if(vis[xy[i].bh]==0){
					if(sz[xy[i].gs]+1<=n/2){
						res+=a[xy[i].bh][xy[i].gs];
						vis[xy[i].bh]=1;
						sz[xy[i].gs]++;
						num++;
					}
				}
			}else{
				pos=i;
				break;
			}
		}
		int sheng1=n/2-sz[1],sheng23=n-num-sheng1;
		if(pos==-1){
			cout<<res<<'\n';
			return ;
		}
		for(int i=pos;i<=cnt;i++){
			if(xy[i].gs!=1){
				if(vis[xy[i].bh]==0){
					if(sz[xy[i].gs]+1<=n/2){
						if(sheng23>0){
							res+=a[xy[i].bh][xy[i].gs];
							vis[xy[i].bh]=1;
							sz[xy[i].gs]++;
							sheng23--;
						}
					}
				}
			}
		}
		for(int i=1;i<=cnt;i++){
			if(xy[i].gs==1&&vis[xy[i].bh]==0){
				res+=a[xy[i].bh][xy[i].gs];
				vis[xy[i].bh]=1;
				//cout<<xy[i].bh<<' '<<xy[i].gs<<'\n';
			}
		}
		cout<<res<<'\n';
	}
}
void solve(){
	cin>>n;
	bool flag1=1,flag2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0||a[i][2]!=0) flag1=0;
		if(a[i][3]!=0) flag2=0;
	}
	if(flag1){
		Sub_B();
		return ;
	}
	if(flag2){
		Sub_C();
		return ;
	}
	if(n<=10){
		Sub_A();
		return ;
	}
	Sub_D::solve_D();
	return ;
}
bool M2;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int Time=clock();
	int T=1;
    cin>>T;
	while(T--){
		solve();
	}
	//look_memory;
	//look_time;
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

18
4
13
*/
