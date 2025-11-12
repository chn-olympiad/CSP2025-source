#include<bits/stdc++.h>
using namespace std;
struct club{
	int a,b,c;
}m[100005];
int n; 
bool cmp(club x,club y){
	if(x.a==y.a) return x.b>y.b;
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	while(true){
		char p=cin.get();
		if(p=='\n') return 0;
		n=p-'0';
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
		}
		sort(m+1,m+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=m[i].a;
		}
		for(int i=n/2+1;i<=n;i++){
			ans+=m[i].b;
		}
		cout<<ans<<endl;
		char q=cin.get();
	}
	return 0;
} 
