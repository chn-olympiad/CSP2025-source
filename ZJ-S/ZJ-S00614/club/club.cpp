#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct xx{
	int a,b,c,d,e;
}v[N];
bool cmp(xx u,xx v){
	return u.e>=v.e;
}
int t,n,x,y,z,m;
long long ans;
int main(){
	cin.tie();
	cout.tie();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		ans=x=y=z=0;
		for(int i=1;i<=n;i++){
			cin>>v[i].a>>v[i].b>>v[i].c;
			if(v[i].a>=v[i].b && v[i].a>=v[i].c){
				v[i].d=1;
				if(v[i].b>=v[i].c){
					v[i].e=v[i].a-v[i].b;
				}
				else{
					v[i].e=v[i].a-v[i].c;
				}
			}
			else if(v[i].b>=v[i].a && v[i].b>=v[i].c){
				v[i].d=2;
				if(v[i].a>=v[i].c){
					v[i].e=v[i].b-v[i].a;
				}
				else{
					v[i].e=v[i].b-v[i].c;
				}
			}
			else if(v[i].c>=v[i].a && v[i].c>=v[i].b){
				v[i].d=3;
				if(v[i].b>=v[i].a){
					v[i].e=v[i].c-v[i].b;
				}
				else{
					v[i].e=v[i].c-v[i].a;
				}
			}			
		}
		sort(v+1,v+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(v[i].d==1){
				x++;
				ans+=v[i].a;
				if(x>m){
					x--;
					ans-=v[i].e;
				}
			}
			if(v[i].d==2){
				y++;
				ans+=v[i].b;
				if(y>m){
					y--;
					ans-=v[i].e;
				}
			}
			if(v[i].d==3){
				z++;
				ans+=v[i].c;
				if(z>m){
					z--;
					ans-=v[i].e;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
