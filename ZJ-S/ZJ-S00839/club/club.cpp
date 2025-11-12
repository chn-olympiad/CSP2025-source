#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,A=2e4+10;
//chi dao shi la!^V^
inline int read(){
	int x=0;char c=getchar();
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
struct lk{
	int id;
	int c;
	int v;
}a[4][2*N];
bool cmp(lk x,lk y){
	return x.v>y.v;
}
int n;
int dp[101][101];
int csd[N];
int cnt[4];
void solve1(){
	int ans=0;
	memset(dp,0,sizeof(dp));
	for(int s=1;s<=n;s++){
		for(int j=0;j<=s&&j<=n/2;j++){
			for(int k=0;k+j<=s&&k<=n/2;k++){
				int i=s-j-k;
				if(i>n/2)continue;
				if(i>0)dp[i][j]=max(dp[i][j],dp[i-1][j]+a[1][s].v);
				if(j>0)dp[i][j]=max(dp[i][j],dp[i][j-1]+a[2][s].v);
				if(k>0)dp[i][j]=max(dp[i][j],dp[i][j]+a[3][s].v);
				if(s==n)ans=max(ans,dp[i][j]);
				//printf("i=%d	j=%d	k=%d	dp=%d	ans=%d\n",i,j,k,dp[i][j][k],ans);
			}
		}
	}
	printf("%d\n",ans);
}
void solve2(){
	int ans=0;
	sort(a[1]+1,a[1]+n+1,cmp);
	for(int i=1;i<=n/2;i++)ans+=a[1][i].v;
	printf("%d\n",ans);
}


int f[N];
//struct Stu{
//	int id,c;
//	bool operator<(const Stu s)const{
//		return f[id][3-c]<f[s.id][3-s.c];
//	};
//};
//priority_queue<int>q[3];
bool cmp2(int x,int y){
	return a[1][x].v-a[2][x].v>a[1][y].v-a[2][y].v;
}
int nb[N];
void solve3(){
	int ans=0;
	for(int i=1;i<=n;i++)nb[i]=i;
	sort(nb+1,nb+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(i<=n/2)ans+=a[i][nb[i]].v;
		else ans+=a[2][nb[i]].v;
	}
	printf("%d\n",ans);
//	for(int i=1;i<=n;i++){
//		if(csd[a[3][i].id])continue;
//		q[a[3][i].c].push({a[3][i].id,a[3][i].c});
//		if(cnt[a[3][i].c]>n/2){
//			q[a[3][]]
//		}
//	}
//	for(int i=0;i<=n/2;i++){
//		for(int j=n/2;j>=0;j--){
//			if(i>0)f[i]=max(f[i],f[i-1]+a[1][i+j].v);
//			if(j>0)f[i]=max(f[i],f[i]+a[2][i+j].v);
//			printf("i=%d	j=%d	dp=%d	ans=%d\n",i,j,f[i+j],ans);
//			if(i+j==n)ans=max(ans,f[i+j]);
//		}
//	}
	
}
void solve(){
	memset(csd,0,sizeof(csd));
	memset(cnt,0,sizeof(cnt));
	n=read();
	int flag2=0,flag3=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)a[j][i]={i,j,read()};
		if(a[2][i].v>0)flag2=1;
		if(a[3][i].v>0)flag3=1;
//		for(int x=1;x<=3;x++){
//			for(int y=1;y<=3;y++){
//				f[i][x][y]=a[x][i].v-a[y][i].v;
//			}
//		}
	}
	
	if(n<=200)solve1();
	else if(flag2==0)solve2();
	else if(flag3==0)solve3();


	
//	int ans=0;
//	sort(a[1]+1,a[1]+n+1,cmp);
//	sort(a[2]+1,a[2]+n+1,cmp);
//	sort(a[3]+1,a[3]+n+1,cmp);
//	int i=1,j=1,k=1;
//	while(i<=n&&j<=n&&k<=n){
//		while(csd[a[1][i].id])i++;
//		while(csd[a[2][j].id])j++;
//		while(csd[a[3][j].id])k++;
//		if(cnt[1]<n/2){
//			if(f[a[i].id][1][2]>f[a[i].id][1][3])
//		}
//	}
//	printf("%d\n",ans);

}



int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--)solve();
	
	
	return 0;
}


