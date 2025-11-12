#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int sum=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)){sum=sum*10+c-'0';c=getchar();}
	return sum*f;
}
const int N=1e5+5;
int n,ans,F;
int a[N][4];
int f[4];
int pos[N][4];
int sum[N];
int zu(int i){
	if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]) return 1;
	if(a[i][1]<a[i][2]&&a[i][2]>a[i][3]) return 2;
	if(a[i][1]<a[i][3]&&a[i][3]>a[i][2]) return 3;
	return 0;
}
int jian(int i){
	int maxn=max({a[i][1],a[i][2],a[i][3]});
	int tot=-1;
	for(int j=1;j<=3;j++){
		if(a[i][j]!=maxn){
			tot=max(tot,a[i][j]);
		}
	}
	if(tot==-1) return 0;
	else return maxn-tot;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read(),ans=F=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			int x=0;
			for(int j=1;j<=3;j++){
				a[i][j]=read();
				x=max(x,a[i][j]);
			}
			ans+=x;
		}
		for(int i=1;i<=n;i++){
			pos[++f[zu(i)]][zu(i)]=i;
		}
		if(f[1]>n/2){
			for(int i=1;i<=f[1];i++){
				sum[++F]=jian(pos[i][1]);
			}
			sort(sum+1,sum+F+1);
			for(int i=1;i<=f[1]-n/2;i++){
				ans-=sum[i];
			}
		}
		if(f[2]>n/2){
			for(int i=1;i<=f[2];i++){
				sum[++F]=jian(pos[i][2]);
			}
			sort(sum+1,sum+F+1);
			for(int i=1;i<=f[2]-n/2;i++){
				ans-=sum[i];
			}
		}
		if(f[3]>n/2){
			for(int i=1;i<=f[3];i++){
				sum[++F]=jian(pos[i][3]);
			}
			sort(sum+1,sum+F+1);
			for(int i=1;i<=f[3]-n/2;i++){
				ans-=sum[i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}