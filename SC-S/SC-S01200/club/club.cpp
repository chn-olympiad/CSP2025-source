#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,ans;
struct happy{
	int d[5];//三个部门好感度 
	int c[5];//
	int maxc;//最大好感度之差（d[l1]-d[l2]） 
	int minc;//次小好感度之差（d[r1]-d[r2]） 
}a[N];
int cnt[5];

bool cmp(happy x,happy y){
	if(x.maxc!=y.maxc){
		return x.maxc>y.maxc;
	}else if(x.minc!=y.minc){
		return x.minc>y.minc;
	}else{
		for(int i=1;i<=3;i++){
			if(x.d[x.c[i]]!=y.d[y.c[i]])return x.d[x.c[i]]>y.d[y.c[i]];
		}
	}
	
}

void work(){
	for(int i=1;i<=n;i++){
		bool p=0;
		for(int j=1;j<=3;j++){
			if(p)continue;
			int k=a[i].c[j];
			if(cnt[k]<n/2){
				cnt[k]++;
				ans+=a[i].d[k];
				p=1;
			}
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int f[5];
			scanf("%d %d %d",&f[1],&f[2],&f[3]);
			a[i].d[1]=f[1], a[i].d[2]=f[2], a[i].d[3]=f[3];
			int Max=-1,Min=N,Mid,g[5];//最大值，中间值，最小值
			for(int j=1;j<=3;j++){
				if(Max<f[j]){
					Max=f[j],g[1]=j;
				}
				if(Min>f[j]){
					Min=f[j],g[3]=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(j!=g[1]&&j!=g[3]){
					Mid=f[j];
					g[2]=j;
					break;
				}
			}
			a[i].c[1]=g[1];
			a[i].c[3]=g[3];
			a[i].maxc=Max-Min;
			a[i].minc=max(Max-Mid,Mid-Min);
//			if(Max-Mid>Mid-Min){
			a[i].c[2]=g[2];
//			}else{
//				a[i].c[2]=
//			}
		}
		
		sort(a+1,a+n+1,cmp);
		work();
		printf("%d\n",ans);
	}
	return 0;
}