#include<bits/stdc++.h>
using namespace std;
struct kun{
	int a[4],ma;
}m[100005];
struct p{
	int i,n;//bianhao cha
	bool operator < (const p &a)const{
		return n<a.n;
	}
};
priority_queue< p ,vector<p> > q;//da zai shang
int t,n,a1,a2,a3,cl,aa;
long long ans;
bool vis[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		a1=a2=a3=aa=cl=0;
//		kun aa={{0,0,0,0},0};
//		memset(m,sizeof(m),aa);
		ans=0;
		while(!q.empty())q.pop();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&m[i].a[1],&m[i].a[2],&m[i].a[3]);
			if(m[i].a[1]>m[i].a[2] && m[i].a[1]>m[i].a[3]){
				m[i].ma=1;a1++;
				ans+=m[i].a[1];
			} 
			else if(m[i].a[3]>m[i].a[2]){
				m[i].ma=3;a3++;
				ans+=m[i].a[3];
			} 
			else {
				m[i].ma=2;a2++;
				ans+=m[i].a[2];
			}
		}
		if(a1>a2 && a1>a3){
			if(a1<=n/2){
				printf("%d\n",ans);
				continue;
			}
			aa=a1;
			cl=1;
		}
		else if(a2>a3){
			if(a2<=n/2){
				printf("%d\n",ans);
				continue;
			}
			aa=a2;
			cl=2;
		}
		else {
			if(a3<=n/2){
				printf("%d\n",ans);
				continue;
			}
			aa=a3;
			cl=3;
		}
		for(int i=1;i<=n;i++){
			if(m[i].ma==cl){
				for(int j=1;j<=3;j++){
					if(j!=cl){
						q.push({i,m[i].a[j]-m[i].a[cl]});
					}
					
				}
			}
		}
		for(int i=1;i<=aa-n/2;++i){
			p x=q.top();
			q.pop();
			if (!vis[x.i]){
				ans+=x.n;
				vis[x.i]=1;
				continue;
			}
			i--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
