#include<bits/stdc++.h>
#define N 100005
using namespace std;
int t,n,A=1,B=1,ans;
struct man{
	int m0,m1,m2;
}a[N];
bool cmp1(man a,man b){
	return a.m0>b.m0;
}
bool cmp2(man a,man b){
	return abs(a.m0-a.m1)>abs(b.m0-b.m1);
}
void dfs(int x,int k1,int k2,int k3,int sum){
	if(k1>n/2||k2>n/2||k3>n/2) return ;
	if(x==n){
		ans=max(ans,sum);
		return ;
	}
	dfs(x+1,k1+1,k2,k3,sum+a[x+1].m0);
	dfs(x+1,k1,k2+1,k3,sum+a[x+1].m1);
	dfs(x+1,k1,k2,k3+1,sum+a[x+1].m2);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].m0,&a[i].m1,&a[i].m2);
			if(a[i].m1!=0) A=0;
			if(a[i].m2!=0) A=0,B=0;
		}
		if(A){
			sort(a+1,a+n+1,cmp1);
			long long sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i].m0;
			}
			printf("%lld\n",sum);
		}
		else if(B){
			sort(a+1,a+n+1,cmp2);
			long long sum=0,k1=0,k2=0;
			for(int i=1;i<=n;i++){
				if(k1==n/2) sum+=a[i].m1;
				else if(k2==n/2) sum+=a[i].m0;
				else{
					if(a[i].m1>a[i].m0){
						sum+=a[i].m1;
						k2++;
					}		
					else{
						sum+=a[i].m0;
						k1++;
					}			
				}
			}
			printf("%lld\n",sum);
		}
		else{
			dfs(0,0,0,0,0);
			cout<<ans<<'\n';
		}
	}
	return 0;
} 
