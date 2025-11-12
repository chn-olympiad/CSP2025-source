#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Nobe{
	int a,b,c;
	bool use=false;
};
struct Nobe1{
	int d;
	int type;
};
bool cmp(Nobe1 a,Nobe1 b){
	return a.d>b.d;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		vector<Nobe> p;
		for(int j=0;j<n;j++){
			int a,b,c;
			cin>>a>>b>>c;
			p.push_back({a,b,c,false});
		}
		int b1m,b2m,b3m;
		b1m=b2m=b3m=0;
		vector<Nobe1> b1,b2,b3;
		for(int j=0;j<n;j++){
			b1.push_back({p[j].a,1});
			b2.push_back({p[j].b,2});
			b3.push_back({p[j].c,3});
		}
		sort(b1.begin(),b1.end(),cmp);
		sort(b2.begin(),b2.end(),cmp);
		sort(b3.begin(),b3.end(),cmp);
		int ans=0;
		for(int j=0;j<n;j++){
			Nobe1 x=b1[j],y=b2[j],z=b3[j];
			vector<Nobe1> tmp;
			tmp.push_back({x.d,1});
			tmp.push_back({y.d,2});
			tmp.push_back({z.d,3});
			sort(tmp.begin(),tmp.end(),cmp);
			if(tmp[1].type==1&&b1m<n/2&&p[x.type].use==false){
				ans+=tmp[1].d;
				p[x.type].use=true;
			}
			if(tmp[1].type==2&&b2m<n/2&&p[y.type].use==false){
				ans+=tmp[1].d;
				p[y.type].use=true;
			}
			if(tmp[1].type==3&&b3m<n/2&&p[z.type].use==false){
				ans+=tmp[1].d;
				p[z.type].use=true;
			}
			if(tmp[2].type==1&&b1m<n/2&&p[x.type].use==false){
				ans+=tmp[2].d;
				p[x.type].use=true;
			}
			if(tmp[2].type==2&&b2m<n/2&&p[y.type].use==false){
				ans+=tmp[2].d;
				p[y.type].use=true;
			}
			if(tmp[2].type==3&&b3m<n/2&&p[z.type].use==false){
				ans+=tmp[2].d;
				p[z.type].use=true;
			}
			if(tmp[3].type==1&&b1m<n/2&&p[x.type].use==false){
				ans+=tmp[3].d;
				p[x.type].use=true;
			}
			if(tmp[3].type==2&&b2m<n/2&&p[y.type].use==false){
				ans+=tmp[3].d;
				p[y.type].use=true;
			}
			if(tmp[3].type==3&&b3m<n/2&&p[z.type].use==false){
				ans+=tmp[3].d;
				p[z.type].use=true;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}