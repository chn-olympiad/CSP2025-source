#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,T,a[N][5],cnt[N],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		priority_queue<int>qu[5];
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int mx=-1,sx=-1,my=0;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>mx){
					sx=mx;
					mx=a[i][j];
					my=j;
				}
				else if(a[i][j]>sx){
					sx=a[i][j];
				}
			}cnt[my]++;ans+=mx;
			qu[my].push(sx-mx);
		}
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				while(!qu[i].empty() && cnt[i]>n/2){
					ans+=qu[i].top();
					qu[i].pop();cnt[i]--;
				}break;
			}
		}printf("%d\n",ans);
	}
	return 0;
} 
