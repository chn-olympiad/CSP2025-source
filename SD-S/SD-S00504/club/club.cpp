#include<bits/stdc++.h>
using namespace std;
int t;
struct f{
	int a,b,c;
}a[100010];
int cmp(f a,f b){
	if(a.a==b.a) return a.b<b.b;
	return a.a>b.a;
}
int cmp1(f a,f b){
	if(a.b==b.b) return a.a<b.a;
	return a.b>b.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int m=n/2;
		for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].c;
		sort(a+1,a+1+n,cmp);
		long long ans1=0,ans2=0;
		for(int i=1;i<=m;i++) ans1+=a[i].a;
		for(int i=m+1;i<=n;i++) ans1+=a[i].b;
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=m;i++) ans2+=a[i].b;
		for(int i=m+1;i<=n;i++) ans2+=a[i].a;
		long long ans=max(ans1,ans2);
		cout<<ans<<"\n";
	} 
	return 0;
}

