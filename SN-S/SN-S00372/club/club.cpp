#include<bits/stdc++.h>
using namespace std;
int N,ans,A,B,C;
struct com{
	int a;int b;
}a[100005],b[100005],c[100005];
bool f(com a,com b){
	return a.a<a.b;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>N;
	a[0].b=0;
	while(N--) {
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>b[i].a>>c[i].a;
			a[i].b=a[i-1].b+1;
			b[i].b=b[i-1].b+1;
			c[i].b=c[i-1].b+1;
		}
		sort(a+1,a+n+1,f);
		sort(b+1,b+n+1,f);
		sort(c+1,c+n+1,f);
		for(int i=1;i<=n;i++){
			ans+=max(a[i].a,max(b[i].a,c[i].a));
		}
		cout<<ans;
	}
	return 0;
}
