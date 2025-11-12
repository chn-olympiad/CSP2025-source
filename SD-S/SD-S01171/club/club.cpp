#include<bits/stdc++.h>
using namespace std;
struct club{
	long long a,b,c,l,maxx;
	long long zcha;
	bool operator<(const club &A)const{
		return zcha<A.zcha;
	}
}a[100005];
long long n,numa=0,numb=0,numc=0,ans=0;
void dfs(long long x,long long sum){
	if(x>n){
		ans=max(sum,ans);
		return ;
	}
	if(numa<n/2){
		numa++;
		dfs(x+1,sum+a[x].a);
		numa--;
	}
	if(numb<n/2){
		numb++;
		dfs(x+1,sum+a[x].b);
		numb--;
	}
	if(numc<n/2){
		numc++;
		dfs(x+1,sum+a[x].c);
		numc--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		numa=0,numb=0,numc=0,ans=0;
		for(long long i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			a[i].l=i;
			a[i].maxx=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].a<=a[i].b&&a[i].a<=a[i].c){
				if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
					a[i].zcha=a[i].b-a[i].c;
				}
				else{
					a[i].zcha=a[i].c-a[i].b;
				}
			}
			else if(a[i].b<=a[i].a&&a[i].b<=a[i].c){
				if(a[i].c>=a[i].a&&a[i].c>=a[i].b){
					a[i].zcha=a[i].c-a[i].a;
				}
				else{
					a[i].zcha=a[i].a-a[i].c;
				}
			}
			else{
				if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
					a[i].zcha=a[i].b-a[i].a;
				}
				else{
					a[i].zcha=a[i].a-a[i].b;
				}
			}
		}
		sort(a+1,a+n+1);
		if(n<=10){
			dfs(1,0);
			printf("%lld\n",ans);
			continue;
		}
		for(long long i=n;i>=1;i--){
			if(numa>=n/2){
				if(a[i].b>=a[i].c){
					numb++;
					ans+=a[i].b;
				}
				else{
					numc++;
					ans+=a[i].c;
				}
			}
			else if(numb>=n/2){
				if(a[i].a>=a[i].c){
					numa++;
					ans+=a[i].a;
				}
				else{
					numc++;
					ans+=a[i].c;
				}
			}
			else if(numc>=n/2){
				if(a[i].b>=a[i].a){
					numb++;
					ans+=a[i].b;
				}
				else{
					numa++;
					ans+=a[i].a;
				}
			}
			else{
				if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
					numa++;
//					if(a[i].maxx!=a[i].a){
//						printf("NOa%lld\n",a[i].l);
//					}
					ans+=a[i].a;
				}
				else if(a[i].b>=a[i].c&&a[i].b>=a[i].a){
					numb++;
//					if(a[i].maxx!=a[i].b){
//						printf("NOb%lld\n",a[i].l);
//					}
					ans+=a[i].b;
				}
				else{
					numc++;
//					if(a[i].maxx!=a[i].c){
//						printf("NOc%lld\n",a[i].l);
//					}
					ans+=a[i].c;
				}
//				else{
//					printf("NOd%lld\n",a[i].l);
//					printf("%lld %lld %lld\n",a[i].a,a[i].b,a[i].c);
//				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
