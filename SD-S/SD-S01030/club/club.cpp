#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
struct node{
	int a,b,c;
}d[MAXN];
bool cmp1(node a,node b){
	return a.a>b.a;
}
long long ans=0;
int vis[4];
void dfs(int k,long long sum,int n){
	if(k==n){
		if(ans<sum)ans=sum;
		return;
	}
	if(vis[1]<n/2){
		vis[1]++;
		dfs(k+1,sum+d[k].a,n);
		vis[1]--;
	}
	if(vis[2]<n/2){
		vis[2]++;
		dfs(k+1,sum+d[k].b,n);
		vis[2]--;
	}
	if(vis[3]<n/2){
		vis[3]++;
		dfs(k+1,sum+d[k].c,n);
		vis[3]--;
	}
}
struct ioer{
	int val,ooer,part;
}iier[MAXN*2];
int top=0;
bool cmp2(ioer a,ioer b){
	return a.val>b.val;
}
bool vis2[MAXN];
int vis3[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		bool Sp_A=1,Sp_B=1;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
			if(d[i].c!=0){
				Sp_A=0;
				Sp_B=0;
			}else if(d[i].b!=0){
				Sp_A=0;
			}
		}
//		cout<<Sp_A<<endl;
		if(Sp_A==1){
			long long sum=0;
			sort(d,d+n,cmp1);
			for(int i=0;i<n/2;i++){
				sum+=d[i].a;
			}
			cout<<sum<<endl;
		}else if(Sp_B==1){
			top=0;
			memset(iier,0,sizeof(vis));
			memset(vis2,0,sizeof(vis));
			memset(vis3,0,sizeof(vis));
			long long sum=0;
			for(int i=0;i<n;i++){
				iier[top]=(ioer){d[i].a,i,1};
				top++;
				iier[top]=(ioer){d[i].b,i,2};
				top++;
			}
			sort(iier,iier+top,cmp2);
			for(int i=0;i<top;i++){
				if(!vis2[iier[i].ooer]&&vis3[iier[i].part]<n/2){
					vis2[iier[i].ooer]=1;
					vis3[iier[i].part]++;
					sum+=iier[i].val;
				}
			}
			cout<<sum<<endl;
		}else{
			memset(vis,0,sizeof(vis));
			ans=0;
			dfs(0,0,n);
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
/*
1
4
5 8 2
6 9 2
0 6 0
0 1 0

*/
