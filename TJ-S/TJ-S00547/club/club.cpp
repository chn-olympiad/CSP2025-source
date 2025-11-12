#include<bits/stdc++.h>
using namespace std;
struct s{
	long long a,b,c,d,e;
}a[100010];
bool cmp(s x,s y){
	if(x.d==y.d){
		return x.e>y.e;
	}
	else{
		return x.d>y.d;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long ans=0,n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].d=max(a[i].a,max(a[i].b,a[i].c));
			a[i].e=(a[i].a+a[i].b+a[i].c-a[i].d);
		}
		sort(a+1,a+1+n,cmp); //到这里开始发现不会了 
		for(int i=1;i<=(n/2);i++){
			ans+=a[i].d;
		}
		for(int i=(n/2)+1;i<=n;i++){
			ans+=a[i].e;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
