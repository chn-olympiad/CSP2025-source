#include<bits/stdc++.h>
using namespace std;
int t,n,b[100005],sum;
long long ans;
int a[100005][5];
struct node{
	int fi,se,cha;
}c[100005];
bool cmp(node e,node r){
	return e.cha<r.cha;
}
void dfs(int cnt1,int cnt2,int cnt3,int cnt,long long maxx){
	if(cnt==n+1){
		ans=max(ans,maxx);
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			if(cnt1<n/2){
				dfs(cnt1+1,cnt2,cnt3,cnt+1,maxx+a[cnt][i]);
			}
			else{
				continue;
			}
		}
		if(i==2){
			if(cnt2<n/2){
				dfs(cnt1,cnt2+1,cnt3,cnt+1,maxx+a[cnt][i]);
			}
			else{
				continue;
			}
		}
		if(i==3){
			if(cnt3<n/2){
				dfs(cnt1,cnt2,cnt3+1,cnt+1,maxx+a[cnt][i]);
			}
			else{
				continue;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sum=0;
		memset(b,0,sizeof(b));
		ans=0;
		scanf("%d",&n);
		int flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			if(a[i][2]!=0){
				flag1=1;
			}
			if(a[i][3]!=0){
				flag2=1;
			}
		}
		if(n<=10){
			dfs(0,0,0,1,(long long)(0));
			printf("%lld\n",ans);
			continue;
		}
		else if(flag1==0&&flag2==0){
			for(int i=1;i<=n;i++){
				b[++sum]=a[i][1];
			}
			sort(b+1,b+sum+1);
			for(int i=sum;i>=sum/2;i--){
				ans+=b[i];
			}
			printf("%lld\n",ans);
			continue;
		}
		else if(flag2==0){
			for(int i=1;i<=n;i++){
				c[i].fi=a[i][1];
				c[i].se=a[i][2];
				c[i].cha=max(a[i][1],a[i][2])-min(a[i][1],a[i][2]);
			}
			sort(c+1,c+n+1,cmp);
			int sum1=0,sum2=0;
			for(int i=n;i>=1;i--){
				if(c[i].fi>c[i].se){
					if(sum1<n/2){
						ans+=c[i].fi;
						sum1++;
					}
					else{
						ans+=c[i].se;
						sum2++;
					}
				}
				else if(c[i].fi<c[i].se){
					if(sum2<n/2){
						ans+=c[i].se;
						sum2++;
					}
					else{
						ans+=c[i].fi;
						sum1++;
					}
				}
				else{
					ans+=c[i].fi;
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		else{
			for(int i=1;i<=n;i++){
				ans+=max(max(a[i][1],a[i][2]),a[i][2]);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
} 
//-static -Wall -Wextra -std=c++14 -O2 -Wl,--stack=1000000000 -Wshadow
