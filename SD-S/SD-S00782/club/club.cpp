#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
inline void chmx(int &x,int y){x=max(x,y);}
struct Per{int c[3],num;}a[N];//num没用 
int t,n,hn,p[N],c[3],ans,f[205][105][105];
bool SPEA,SPEB;
inline void dfs(int p,int s){
	if(p>n){
		chmx(ans,s);
		return;
	}
	if(c[0]<hn) c[0]++,dfs(p+1,s+a[p].c[0]),c[0]--;
	if(c[1]<hn) c[1]++,dfs(p+1,s+a[p].c[1]),c[1]--;
	if(c[2]<hn) c[2]++,dfs(p+1,s+a[p].c[2]),c[2]--;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){//确保每个case都有输出 
		SPEA=SPEB=1,ans=0;
		cin>>n;
		hn=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].c[0]>>a[i].c[1]>>a[i].c[2];
			a[i].num=i;
			if(a[i].c[1]||a[i].c[2]) SPEA=0;
			if(a[i].c[2]) SPEB=0;
		}
		if(n<=10){//20pts Brute
			dfs(1,0);
			cout<<ans<<"\n";
		}else if(SPEA){//5pts SPEA
			sort(a+1,a+1+n,[](Per a,Per b){return a.c[0]>b.c[0];});
			for(int i=1;i<=hn;i++) ans+=a[i].c[0];
			cout<<ans<<"\n";
		}else if(n<=200){//35pts O(n^3) DP
			for(int i=1;i<=n;i++){
				for(int j=0;j<=i;j++){
					if(j>hn) break;
					for(int k=i-j-hn;k+j<=i;k++){//i-j-k<=hn
						if(k>hn) break;
						f[i][j][k]=f[i-1][j][k]+a[i].c[2];
						if(j) chmx(f[i][j][k],f[i-1][j-1][k]+a[i].c[0]);
						if(k) chmx(f[i][j][k],f[i-1][j][k-1]+a[i].c[1]);
					}
				}
			}
			for(int i=0;i<=n;i++){
				if(i>hn) break;
				for(int j=n-hn-i;j+i<=n;j++){//n-i-j<=hn
					if(j>hn) break;
					chmx(ans,f[n][i][j]);
				}
			}
			cout<<ans<<"\n";
		}else if(SPEB){//0pts SPEB
			int s1=0,s2=0;
			sort(a+1,a+1+n,[](Per a,Per b){return a.c[0]>b.c[0];});
			for(int i=1;i<=hn;i++) s1+=a[i].c[0];
			for(int i=hn+1;i<=n;i++) s1+=a[i].c[1];
			sort(a+1,a+1+n,[](Per a,Per b){return a.c[1]>b.c[1];});
			for(int i=1;i<=hn;i++) s2+=a[i].c[1];
			for(int i=hn+1;i<=n;i++) s2+=a[i].c[0];
			cout<<max(s1,s2)<<"\n";
		}else{//10pts SPEC
			for(int i=1;i<=n;i++){
				ans+=max({a[i].c[0],a[i].c[1],a[i].c[2]});
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
