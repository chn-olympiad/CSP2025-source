#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=1e5+100;
int T,n,a[4][N],ans,mx,pos,t[4],x[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		priority_queue<int>q;
		memset(t,0,sizeof t);
		memset(x,0,sizeof x);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[1][i],&a[2][i],&a[3][i]);
			mx=-1,pos=0;
			for(int j=1;j<=3;j++){
				if(a[j][i]>mx)mx=a[j][i],pos=j;
			}
			t[pos]++;
			x[i]=pos;
			ans+=a[pos][i];
		}
		if(t[1]<=n/2&&t[2]<=n/2&&t[3]<=n/2){
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=3;i++)if(t[i]>n/2)pos=i;
		for(int i=1;i<=n;i++){
			if(x[i]!=pos)continue;
			mx=-1e9;
			for(int j=1;j<=3;j++){
				if(j==pos)continue;
				mx=max(a[j][i]-a[pos][i],mx);
			}
			q.push(mx);
		}
		while(q.size()>n/2){
			ans+=q.top();
			q.pop();
		}
		printf("%d\n",ans);
	}
}