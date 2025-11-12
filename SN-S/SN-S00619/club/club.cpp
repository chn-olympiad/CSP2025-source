#include<bits/stdc++.h>
using namespace std;
struct p{
	int a,b,c;
}w[200000];
bool cmp(p x,p y){
	int maxx=max(x.a,max(x.b,x.c));
	int maxy=max(y.a,max(y.b,y.c));
	return maxx>maxy;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool A=1;
		for(int i=1;i<=n;i++){
			cin>>w[i].a>>w[i].b>>w[i].c;
			if(w[i].b!=0)A=0;
		} 
		
		sort(w+1,w+1+n,cmp);
		int r=0;
		long long ans=0;
		if(A){
			for(int i=1;i<=n/2;i++){
				ans+=w[i].a;
			}
		}
		else for(int i=1;i<=n;i++){
			if(w[i].a>w[i].b&&r*2<=n){
				ans+=w[i].a;
				r++;
			}
			else ans+=w[i].b;
		}
		cout<<ans<<endl;
	} 
} 
