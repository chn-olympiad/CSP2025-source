#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],ans,cnt[5],w[100005];
bool b[100005];
priority_queue<int> p[5];
struct SC{
	int x,id,k;
}g[300005],f[100005];
bool cmp(SC x,SC y){
	return x.x>y.x;
}
int read(){
	int res=0,f=1;char ch=getchar();
	while(isdigit(ch)){if(ch=='-') f=-f; ch=getchar();}
	while(!isdigit(ch)) res=(res*10)+(ch-'0'),ch=getchar();
	return res*f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	/*p.push(1);
	p.push(2);
	printf("%d\n",p.top());
	p.pop();
	printf("%d\n",p.top());*/
	scanf("%d",&t);
	while(t--){
		while(!p[1].empty()) p[1].pop();
		while(!p[2].empty()) p[2].pop();
		while(!p[3].empty()) p[3].pop();
		memset(b,0,sizeof b);
		ans=0,cnt[1]=cnt[2]=cnt[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			g[(i-1)*3+1]=(SC){a[i][1],i,1},g[(i-1)*3+2]=(SC){a[i][2],i,2},g[i*3]=(SC){a[i][3],i,3};
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				if(a[i][2]>a[i][3]) f[i]=(SC){a[i][1]-a[i][2],1,2},w[i]=a[i][2];
				else f[i]=(SC){a[i][1]-a[i][3],1,3},w[i]=a[i][3];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				if(a[i][1]>a[i][3]) f[i]=(SC){a[i][2]-a[i][1],2,1},w[i]=a[i][1];
				else f[i]=(SC){a[i][2]-a[i][3],2,3},w[i]=a[i][3];
			}
			else{
				if(a[i][2]>a[i][1]) f[i]=(SC){a[i][3]-a[i][2],3,2},w[i]=a[i][2];
				else f[i]=(SC){a[i][3]-a[i][1],3,1},w[i]=a[i][1];
			}
		}
		//for(int i=1;i<=n;i++) printf("///%d\n",w[i]);
		//for(int i=1;i<=n;i++) printf("///%d\n",f[i].x);
		sort(g+1,g+1+n*3,cmp);
		for(int i=1;i<=n*3;i++){
			if(b[g[i].id]) continue;
			//printf("%d %d %d %d %d\n",g[i].x,g[i].id,g[i].k,cnt[g[i].k],ans);
			if(cnt[g[i].k]==n/2){
				//printf("//%d %d %d\n",p[g[i].k].top(),g[i].x,w[g[i].id]);
				if((p[g[i].k].top()+g[i].x>w[g[i].id])||(p[g[i].k].top()+g[i].x==w[g[i].id]&&-f[g[i].id].x>p[g[i].k].top())){
					
					b[g[i].id]=1;
					ans+=p[g[i].k].top()+g[i].x;
					p[g[i].k].pop();
					p[g[i].k].push(-f[g[i].id].x);
				}
			}
			else{
				b[g[i].id]=1;
				cnt[g[i].k]++;
				ans+=(g[i].x);
				p[g[i].k].push(-f[g[i].id].x);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}