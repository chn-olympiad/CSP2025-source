#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}p[100005];
bool cmpa(node a,node b){
	return a.a>b.a;
}
bool cmpb(node a,node b){
	return a.b>b.b;
}
bool cmpc(node a,node b){
	return a.c>b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,ans=0;
		cin >> n;
		if(n==2){
			int a,b,c,d,e,f;
			cin >> a >> b >> c >> d >> e >> f;
			ans = max(a+e,max(a+f,max(b+d,max(b+f,max(c+d,c+e)))));
			cout << ans << '\n';
			continue;
		}
		for(int i = 1;i<=n;i++){
			cin >> p[i].a >> p[i].b >> p[i].c;
		}
		if(p[1].b==0&&p[1].c==0){
			int ansa=0;
			sort(p+1,p+1+n,cmpa);
			for(int i = 1;i<=n/2;i++){
				ansa+=p[i].a;
			}
			cout << ansa<<'\n';
		}else if(p[1].c==0){
			int ansb=0,ansa=0,ansbb=0,ansaa=0;
			sort(p+1,p+1+n,cmpb);
			for(int i = 1;i<=n/2;i++){
				ansb+=p[i].b;
			}
			for(int i = n/2+1;i<=n;i++){
				ansb+=p[i].a;
			}
			for(int i = 1;i<n/2;i++){
				ansbb+=p[i].b;
			}
			for(int i = n/2;i<=n;i++){
				ansbb+=p[i].a;
			}
			sort(p+1,p+1+n,cmpa);
			for(int i = 1;i<=n/2;i++){
				ansa+=p[i].a;
			}
			for(int i = n/2+1;i<=n;i++){
				ansa+=p[i].b;
			}
			for(int i = 1;i<n/2;i++){
				ansaa+=p[i].a;
			}
			for(int i = n/2;i<=n;i++){
				ansaa+=p[i].b;
			}
			cout << max(ansa,max(ansb,max(ansaa,ansbb))) << '\n';
		}else if(n==4){
			int ansa=0,ansb=0,ansc=0;
			sort(p+1,p+n+1,cmpa);
			int o,l,i,j,su;
			if(p[3].b>p[4].b){
				o=p[3].b;
				l=p[4].c;
			}
			if(p[3].c>p[4].c){
				i = p[3].c;
				j = p[4].b;
			}
			su=max(o+l,i+j);
			ansa=p[1].a+p[2].a+su;
			sort(p+1,p+n+1,cmpb);
			if(p[3].a>p[4].a){
				o=p[3].a;
				l=p[4].c;
			}
			if(p[3].c>p[4].c){
				i = p[3].c;
				j = p[4].a;
			}
			su=max(o+l,i+j);
			ansb=p[1].b+p[2].b+su;
			sort(p+1,p+n+1,cmpc);
			if(p[3].a>p[4].a){
				o=p[3].a;
				l=p[4].b;
			}
			if(p[3].b>p[4].b){
				i = p[3].b;
				j = p[4].a;
			}
			su=max(o+l,i+j);
			ansc=p[1].c+p[2].c+su;
			cout << max(ansa,max(ansb,ansc))<<'\n';
		}

	}
	return 0;
}
