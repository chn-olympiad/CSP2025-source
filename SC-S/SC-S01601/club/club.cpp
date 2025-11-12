#include<bits/stdc++.h>
using namespace std;
int n,t;
int sum,cnt,ans;
struct P{
	int c[4];
}a[100005];
int f[4];
bool cmp1(P x,P y){
	return x.c[1]>y.c[1];
}bool cmp2(P x,P y){
	return x.c[2]>y.c[2];
}
void dfs(int k,int p){
	if(k==n+1){
		ans=max(ans,p);
		return;
	}
	for(int i=1;i<=3;i++){
		if(f[i]<sum){
			f[i]++;
			dfs(k+1,p+a[k].c[i]);
			f[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		bool f1=false,f2=false;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].c[1],&a[i].c[2],&a[i].c[3]);
			if(a[i].c[2]!=0||a[i].c[3]!=0){
				f1=true;
			}if(a[i].c[3]!=0){
				f2=true;
			}
		}sum=n/2;
		for(int i=1;i<=3;i++){
			f[i]=0;
		}ans=0;
		if(n<=30){
			dfs(1,0);
			cout<<ans<<endl;
			continue;
		}else if(f1==false){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=sum;i++){
				ans+=a[i].c[1];
			}cout<<ans<<endl;
		}else if(f2==false){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n;i++){
				ans+=(i<=sum)?a[i].c[1]:a[i].c[2];
			}int sum=0;
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n;i++){
				sum+=(i<=sum)?a[i].c[2]:a[i].c[1];
			}ans=max(ans,sum);
			cout<<ans<<endl;
		}
	}
	return 0;
} 