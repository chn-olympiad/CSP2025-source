#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int T,n;
long long ans=0;
int a1,a2,a3;
struct node {
	int b1;
	int b2;
	int b3;
};
node Map[N];
bool cmp1(node a,node b){
	return a.b1>b.b1;
}
bool cmp2(node a,node b){
	return abs(a.b1-a.b2) > abs(b.b1-b.b2);
}
long long mymax(long long a,long long b){
	if(a<b) return b;
	return a;
}
bool flag=true;
bool tap=true;
void dfs(int now,long long pre,int a,int b,int c,int s){
	if(now==n+1){
		ans=mymax(ans,pre);
		return;
	}
	if(a<s) {
		dfs(now+1,pre+Map[now].b1,a+1,b,c,s);
	}
	if(b<s){
		dfs(now+1,pre+Map[now].b2,a,b+1,c,s);
	}
	if(c<s){
		dfs(now+1,pre+Map[now].b3,a,b,c+1,s);
	}
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		ans=0;
		tap=true;
		flag=true;
		memset(Map,0,sizeof(Map));
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&a1,&a2,&a3);
			Map[i].b1=a1;
			Map[i].b2=a2;
			Map[i].b3=a3;
			if(a2!=0 || a3!=0 ) flag=false;
			if(a3!=0) tap=false;
		}
		if(flag==true){
			sort(Map+1,Map+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=Map[i].b1;
			}
			cout<<ans<<endl;
		}
		else if(tap==true){
			sort(Map+1,Map+n+1,cmp2);
			int s=n/2;
			int cntb1=0,cntb2=0;
			for(int i=1;i<=n;i++){
				if(cntb1==s){
					ans+=Map[i].b2;
				}
				else if(cntb2==s){
					ans+=Map[i].b1;
				}
				else if(Map[i].b1 > Map[i].b2 && cntb1<s) {
					cntb1++;
					ans+=Map[i].b1;
				}
				else if(Map[i].b1 < Map[i].b2 && cntb2<s){
					cntb2++;
					ans+=Map[i].b2;
				}
			}
			cout<<ans<<endl;
		}
		else if(n<=30){
			dfs(0,0,0,0,0,n/2);
			cout<<ans<<endl;
		}
	}
	return 0;
}
