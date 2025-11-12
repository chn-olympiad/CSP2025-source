#include<bits/stdc++.h>
using namespace std;
struct P{
	int a,b;
};
struct NoDe{
	P u[4];
}o[100005];
int T,n,p[4];
long long ans;
bool cmpp(P x,P y){
	return x.a>y.a;
}
bool cmp(NoDe x,NoDe y){
	int xh=x.u[1].a-x.u[2].a,yh=y.u[1].a-y.u[2].a;
	if(xh==yh){
		if(x.u[1].a==y.u[1].a){
			return x.u[3].a>y.u[3].a;
		}
		return x.u[1].a>y.u[1].a;
	}
	return xh>yh;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>o[i].u[1].a>>o[i].u[2].a>>o[i].u[3].a;
			o[i].u[1].b=1,o[i].u[2].b=2,o[i].u[3].b=3;
			sort(o[i].u+1,o[i].u+4,cmpp);
		}
		sort(o+1,o+n+1,cmp);
		p[1]=n/2,p[2]=n/2,p[3]=n/2;
		for(int i=1;i<=n;i++){
			for(int k=1;k<=3;k++){
				if(p[o[i].u[k].b]!=0){
					p[o[i].u[k].b]--;
					ans+=o[i].u[k].a;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 