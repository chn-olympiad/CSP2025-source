#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+30;
const int M=5e6+10;
const int INF=0x3f3f3f3f;
const int P=998244353;
int n,m;
struct node{
	char c;
	int b;
}a[N],e[N];
bool vis[N];
ll ans;
char c[N];
void pertion(int x,node d[]){
	if(x==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(d[i].c=='0'){
				cnt++;
			}else{
				if(cnt>=d[i].b) cnt++;
			}
		}
		if(n-cnt>=m) ans=(ans+1)%P;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		d[x].c=a[i].c;
		d[x].b=a[i].b;
		pertion(x+1,d);
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",c+1);
	for(int i=1;i<=n;i++){
		a[i].c=c[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].b);
	}
	pertion(1,e);
	printf("%lld\n",ans);
	return 0;
}
