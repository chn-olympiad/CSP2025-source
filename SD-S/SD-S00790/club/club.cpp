#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct node{
	int a,b,c;
}m[10010];
bool cmp(node x,node y){
	return x.b>y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		int a=0,c=0;
		if(n==2){
			cin>>m[1].a>>m[1].b>>m[1].c;
			cin>>m[2].a>>m[2].b>>m[2].c;
			ans=max(max(max(m[1].a+m[2].a,m[1].a+m[2].b),max(m[1].a+m[2].c,m[1].b+m[2].a)),max(max(m[1].b+m[2].b,m[1].b+m[2].c),m[1].c+m[1].a));
			ans=max(ans,max(m[1].c+m[2].b,m[1].c+m[2].c));
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
		}
		for(int i=1;i<=n;i++){
			a+=m[i].a;
			c+=m[i].c;
		}
		if(c==0 and a!=0){
			for(int i=1;i<=n;i++){
				ans+=max(max(m[i].a,m[i].b),m[i].c);
			}
			cout<<ans<<endl;
			continue;
		}
		if(a==0 and c==0){
			sort(m+1,m+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=m[i].b;
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			ans+=max(max(m[i].a,m[i].b),m[i].c);
		}
		cout<<ans<<endl;
	}
	return 0;
}
