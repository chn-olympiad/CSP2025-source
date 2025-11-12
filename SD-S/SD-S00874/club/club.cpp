#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int a,b,c;
}a[N];
int n,T,ans;
bool cmp1(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.b>y.b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		if(a[1].b==0 && a[1].c==0){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++)ans+=a[i].a;
			cout<<ans<<"\n";
		}
		else{
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n/2;i++)ans+=a[i].b,a[i].a=0;
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++)ans+=a[i].a,a[i].b=0;
			cout<<ans<<"\n";
		}
	}
	

	return 0;
}
