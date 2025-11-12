#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long t;
long long n;
struct node{
	long long a,b,c,g;
}d[100005];
bool cmp(node x,node y){
	if(x.a==y.a){
		return x.b>y.b;
	}
	return x.a>y.a;
}
bool cp(node x,node y){
	return x.g>y.g;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
		}
		sort(d+1,d+n+1,cmp);
		for(int i=1;i<=n;i++){
			d[i].g=d[i].a-d[i].b;
		}
		sort(d+1,d+n+1,cp);
		for(int i=1;i<=n/2;i++){
			sum+=d[i].a;
		}
		for(int i=n/2+1;i<=n;i++){
			sum+=d[i].b;
		}
		cout<<sum<<"\n";
	}
	
	return 0;
}

