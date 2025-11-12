#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N][4],b[N][4];
int match[N];
int st[N];
int n;
int k;
bool find(int u){
	for(int i=1;i<=3;i++){
		int o=b[u][i];
		for(int j=1;j*o<=k;j++){
			int t=o*j;
			if(!match[t]){
				match[t]=u;
				st[u]=o;
				return 1;
			}
			else{
				if(a[u][o]>a[match[t]][o]){
					if(find(match[t])){
						match[t]=u;
						st[u]=o;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		k=n/2*3;
		memset(st,0,sizeof st);
		memset(a,0,sizeof a);
		memset(match,0,sizeof match);
		memset(b,0,sizeof b);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>a[i][b[i][1]]){
					b[i][3]=b[i][2];
					b[i][2]=b[i][1];
					b[i][1]=j;
				}
				else if(a[i][j]>a[i][b[i][2]]){
					b[i][3]=b[i][2];
					b[i][2]=j;
				}
				else{
					b[i][3]=j;
				}
			}
			//cout<<b[i][1]<<endl;
		}
		for(int i=1;i<=n;i++){
			if(!st[i]){
				find(i);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i][st[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
} 
