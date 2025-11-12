#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,mod=1e9+7;
int n,ans,a[N][3];
struct node{
	int id,x;
}r;
priority_queue<int,vector<int>,greater<int> >q[4];
inline int read(){int x(0),f(1);char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-') f=-1;for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);return x*f;}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	int cc=clock();
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				a[i][j]=read();
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				q[0].push(min(a[i][0]-a[i][1],a[i][0]-a[i][2]));
				ans+=a[i][0];
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				q[1].push(min(a[i][1]-a[i][0],a[i][1]-a[i][2]));
				ans+=a[i][1];
			}
			else{
				q[2].push(min(a[i][2]-a[i][0],a[i][2]-a[i][1]));
				ans+=a[i][2];
			}
		}
		while((int)q[0].size()>n/2){
			int x=q[0].top();q[0].pop();
			ans-=x;
		}
		while((int)q[1].size()>n/2){
			int x=q[1].top();q[1].pop();
			ans-=x;
		}
		while((int)q[2].size()>n/2){
			int x=q[2].top();q[2].pop();
			ans-=x;
		}
		printf("%lld\n",ans);
		while(!q[0].empty()) q[0].pop();
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
	}
//	printf("\n%d",clock()-cc);
	return 0;
}
/*

*/
