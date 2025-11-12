#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
struct note{
	int a1,a2,a3;
};
bool cmp(note a,note b){
	return a.a1>b.a1;
}
bool cmp2(note a,note b){
	if(a.a1==b.a1) return a.a2>b.a2;
	return a.a2>b.a2;
}
bool cmmp1(note a,note b){
	return a.a1>b.a1;
}
bool cmmp2(note a,note b){
	return a.a2>b.a2;
}
bool cmmp3(note a,note b){
	return a.a3>b.a3;
}
int T,n,numb1,numb2;
bool b1,b2,b3;
LL maxn,summ;
note a[100005];
void dfs(int o1,int o2,int o3,LL sum,int depth){
	if(depth==n){
		maxn=max(maxn,sum);
		return ;
	}
	if(o1>0) dfs(o1-1,o2,o3,sum+a[depth+1].a1,depth+1);
	if(o2>0) dfs(o1,o2-1,o3,sum+a[depth+1].a2,depth+1);
	if(o3>0) dfs(o1,o2,o3-1,sum+a[depth+1].a3,depth+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		summ=maxn=0;
		b1=b2=b3=false;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].a1,&a[i].a2,&a[i].a3);
			b1=b1|a[i].a1;
			b2=b2|a[i].a2;
			b3=b3|a[i].a3;
		}
		if(false&&n<=10){
			maxn=0;
			dfs(n/2,n/2,n/2,0,0);
			printf("%lld\n",maxn);
		}
		else if(false&&(b2|b3)==0){
			sort(a+1,a+n+1,cmp);
			summ=0;
			for(int i=n/2;i>=1;i--) summ+=a[i].a1;
			printf("%lld\n",summ);
		}
		else if(b3==0){
			numb1=numb2=n/2;
			sort(a+1,a+1+n,cmp2);
			summ=0;
			for(int i=1;i<=n;i++){
				if(a[i].a1>a[i].a2&&numb1>0){
					numb1--;
					summ+=a[i].a1;
				}
				else if(a[i].a1<a[i].a2&&numb2>0){
					numb2--;
					summ+=a[i].a2;
				}
				else if(numb1>0){
					numb1--;
					summ+=a[i].a1;
				}
				else if(numb2>0){
					numb2--;
					summ+=a[i].a2;
				}
			}
			maxn=max(maxn,summ);
			summ=0;
			sort(a+1,a+1+n,cmmp1);
			for(int i=1;i<=n/2;i++){
				summ+=a[i].a1;	
			}
			for(int i=n/2+1;i<=n;i++){
				summ+=a[i].a2;
			}
			maxn=max(maxn,summ);
			summ=0;
			sort(a+1,a+1+n,cmmp2);
			for(int i=1;i<=n/2;i++){
				summ+=a[i].a2;	
			}
			for(int i=n/2+1;i<=n;i++){
				summ+=a[i].a1;
			}
			maxn=max(maxn,summ);
			printf("%lld\n",maxn);
		}
		else{
			summ=0;
			sort(a+1,a+1+n,cmmp1);
			for(int i=1;i<=n/2;i++){
				summ+=a[i].a1;	
			}
			for(int i=n/2+1;i<=n;i++){
				summ+=max(a[i].a2,a[i].a3);
			}
			maxn=max(maxn,summ);
			summ=0;
			sort(a+1,a+1+n,cmmp2);
			for(int i=1;i<=n/2;i++){
				summ+=a[i].a2;	
			}
			for(int i=n/2+1;i<=n;i++){
				summ+=max(a[i].a1,a[i].a3);
			}
			maxn=max(maxn,summ);
			summ=0;
			sort(a+1,a+1+n,cmmp3);
			for(int i=1;i<=n/2;i++){
				summ+=a[i].a3;	
			}
			for(int i=n/2+1;i<=n;i++){
				summ+=max(a[i].a2,a[i].a1);
			}
			maxn=max(maxn,summ);
			printf("%lld\n",maxn);
		}
	}
}