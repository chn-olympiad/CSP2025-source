#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,c;
}a[10005];
int t,n,s_2,s_3,ans;
inline bool cmp1(Node x,Node y){
	return x.a>y.a;
}
inline bool cmp2(Node x,Node y){
	if(x.b!=y.b){
		return x.b<y.b;
	}else{
		return x.a>y.a;
	}
}
inline void dfs(int s1,int s2,int s3,int step,int sum){
	if(s1>n/2||s2>n/2||s3>n/2){
		return;
	}
	if(step>n){
		if(sum>ans){
			ans=sum;
		}
		return;
	}
	dfs(s1+1,s2,s3,step+1,sum+a[step].a);
	dfs(s1,s2+1,s3,step+1,sum+a[step].b);
	dfs(s1,s2,s3+1,step+1,sum+a[step].c);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
			s_2+=a[i].b;
			s_3+=a[i].c;
		}
		if(s_2==0&&s_3==0){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			cout<<ans<<"\n";
		}else if(s_3==0){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i].b;
			}
			cout<<ans<<"\n";
		}else{
			dfs(0,0,0,1,0);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
