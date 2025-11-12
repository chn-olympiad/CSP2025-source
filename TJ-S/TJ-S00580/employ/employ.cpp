#include<cstdio>//8pts
#include<algorithm>
#include<cstring>
using namespace std;
const int N=505,MOD=998244353;
int n,m;
int ans[N];
char s[N];
int c[N];
int vis[N];
int cnt=0;
void DFS(int x){
	if(x>n){
		int dcnt=0,done=0;
		for(int i=1;i<=n;i++){
			if(dcnt>=c[ans[i]]){
				dcnt++;
				continue;
			} 
			if(s[i]=='0'){
				dcnt++;	
				continue;
			} 
			done++;
		}
		if(done>=m) cnt++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		ans[x]=i;
		DFS(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	DFS(1);
	printf("%d",cnt);
	return 0;
}
