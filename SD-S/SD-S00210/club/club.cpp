#include<bits/stdc++.h>
using namespace std;
int n,t,b,c,d,m[10010000],cnt,ans;
struct node{
	int a1,a2,a3;
}a[101000];
//int dfs(int a1){
//	if(cnt==n){
//		return a1;
//	}else{
//		++cnt;
//	}
//	if(b>0){
//		b--;
//		ans=max(ans,dfs(a1+a[cnt].a1));
//		b++;
//		cnt--;
//	}
//	if(c>0){
//		c--;
//		ans=max(ans,dfs(a1+a[cnt].a2));
//		c++;
//		cnt--;
//	}
//	if(d>0){
//		d--;
//		ans=max(ans,dfs(a1+a[cnt].a3));
//		d++;
//		cnt--;
//	}
//	return ans;
//}
bool cmp(node x,node y){
	return x.a1>y.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt=0;
		ans=0;
		cin>>n;
		b=n/2;
		c=n/2;
		d=n/2;
		for(int i=1;i<=n;++i){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;++i){
			ans+=a[i].a1;
		}
		cout<<ans<<endl;
//		cout<<dfs(0)<<endl;
	}
	return 0;
}
