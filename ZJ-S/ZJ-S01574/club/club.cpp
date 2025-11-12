#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z,ans,flagA,flagB,flagC;
struct node{
	int x,y,z;
}a[100010];
bool cmp1(node c,node d){
	return c.x>d.x;
}
bool cmp2(node c,node d){
	return max(c.x,c.y)>max(d.x,d.y);
}
void dfs(int t,int sum1,int sum2,int sum3,int sum){
	if(t>n){
		ans=max(ans,sum);
		return;
	}
	if(sum1+1<=n/2){
		dfs(t+1,sum1+1,sum2,sum3,sum+a[t].x);
	}
	if(sum2+1<=n/2){
		dfs(t+1,sum1,sum2+1,sum3,sum+a[t].y);
	}
	if(sum3+1<=n/2){
		dfs(t+1,sum1,sum2,sum3+1,sum+a[t].z);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0,flagA=1,flagB=1,flagC=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(y!=0)flagA=0;
			if(z!=0)flagB=0;
			if(!(x==0||x==20000)||!(y==0||y==20000)||!(z==0||z==20000))flagC=0;
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
		}else if(flagA){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<"\n";
		}else if(flagB){
			sort(a+1,a+n+1,cmp2);
			int l1=0,l2=0;
			for(int i=1;i<=n;i++){
				if(a[i].x>a[i].y&&l1<=n/2){
					ans+=a[i].x,l1++;
				}else{
					ans+=a[i].y,l2++;
				}
			}
			cout<<ans<<"\n";
		}else if(flagC){
			cout<<20000*n<<"\n";
		}
	}
	return 0;
}
