#include<bits/stdc++.h>
using namespace std;
const int N=1e2+3,M=1e5+10;
int f[N][N][N][N*2];
struct Node{
	int aa,bb,cc,d;
}e[M];
bool cmp(Node x,Node y){
	return x.d>y.d;
}
void work(int n){
	for(int i=1;i<=n;i++){
		cin>>e[i].aa>>e[i].bb>>e[i].cc;
		e[i].d=e[i].aa-e[i].bb;
	}
	sort(e+1,e+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=e[i].aa;
	}
	for(int i=n/2+1;i<=n;i++){
		ans+=e[i].bb;
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;cin>>T;
	while(T--){
		memset(f,0,sizeof f);
		int n;cin>>n;
		if(n>=1e4){
			work(n);
			continue;
		} 
		int mid=n/2,ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int x;cin>>x;
				for(int a=0;a<=min(i,mid);a++){
					for(int b=0;a+b<=i&&b<=mid;b++){
						int c=i-a-b;
						if(c>mid||c<0) continue;
						int t=f[a][b][c][i&1],h=(i-1)&1;
						if(j==1&&a){
							t=max(t,f[a-1][b][c][h]+x);
						}else if(j==2&&b){
							t=max(t,f[a][b-1][c][h]+x);
						}else if(j==3&&c){
							t=max(t,f[a][b][c-1][h]+x);
							
						}
						f[a][b][c][i&1]=t;
						if(i==n){
							
							ans=max(ans,f[a][b][c][n&1]);
							
						} 
						
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	

	return 0;
}

