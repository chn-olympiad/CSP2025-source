#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e5+2;
int T,n,a[N][4],nn,ans,tmp[N];
bool A=1,B=1;
void dfs(int x,int c1,int c2,int c3,int sum){
	if (x==n+1){
		ans=max(ans,sum);
		return ;
	}
	if (c1<nn){
		dfs(x+1,c1+1,c2,c3,sum+a[x][1]);
	}
	if (c2<nn){
		dfs(x+1,c1,c2+1,c3,sum+a[x][2]);
	}
	if (c3<nn){
		dfs(x+1,c1,c2,c3+1,sum+a[x][3]);
	}
}
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		ans=0;
		n=read();
		nn=n/2;
		for (int i=1;i<=n;++i){
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			if (a[i][2]!=0){
				A=0;
			}
			if (a[i][3]!=0){
				A=0;
				B=0;
			}
		}
		if (n<15){
			dfs(1,0,0,0,0);
			cout << ans << "\n";
		}
		if (B){
			int aa=0,bb=0,sum=0;
			for (int i=1;i<=n;++i){
				if(a[i][1]>=a[i][2]){
					++aa;
					sum+=a[i][1];
				}
				else {
					++bb;
					sum+=a[i][2];
				}
			}
			if (aa==bb){
				cout << sum << "\n";
			}
			else if (aa>bb){
				int cnt=0;
				for (int i=1;i<=n;++i){
					if (a[i][1]>=a[i][2])
					tmp[++cnt]=a[i][1]-a[i][2];
				}
				sort(tmp+1,tmp+cnt+1);
				for (int i=1;i<=(aa-bb)/2;++i){
					sum-=tmp[i];
				}
				cout << sum << "\n";
			}
			else{
				int cnt=0;
				for (int i=1;i<=n;++i){
					if (a[i][2]>a[i][1])
					tmp[++cnt]=a[i][2]-a[i][1];
				}
				sort(tmp+1,tmp+cnt+1);
				for (int i=1;i<=(bb-aa)/2;++i){
					sum-=tmp[i];
				}
				cout << sum << "\n";
			}
		}
	}
	return 0;
} 