#include<bits/stdc++.h>
using namespace std;
struct people{
	int a,b,c,num;
};
struct club{
	int num,v;
};
bool cmp(club a,club b){
	return a.v<b.v;
}
int se(people a){
	return a.a+a.b+a.c-max(a.a,max(a.b,a.c))-min(a.a,min(a.b,a.c));
}
int cost(people a){
	return max(a.a,max(a.b,a.c))-se(a);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n,ta,tb,tc,s=0;
		cin>>n;
		vector<club> a={{0,99999999}},b={{0,99999999}},c={{0,99999999}};
		people d[n];
		d[0]={-1,-1,-1,0};
		vector<people> w={{999999,999999,999999,0}};
		for(int i=1;i<=n;i++){
			cin>>ta>>tb>>tc;
			d[i]={ta,tb,tc,i};
			if(ta>=tb&&ta>=tc){
				if((int)a.size()>n/2){
					w.push_back(d[i]);
					s+=se(d[i]);
					continue;
				}
				a.push_back((club){i,cost(d[i])});
				s+=ta;
			}else if(tb>=ta&&tb>=tc){
				if((int)b.size()>n/2){
					w.push_back(d[i]);
					s+=se(d[i]);
					continue;
				}
				b.push_back((club){i,cost(d[i])});
				s+=tb;
			}else{
				if((int)c.size()>n/2){
					w.push_back(d[i]);
					s+=se(d[i]);
					continue;
				}
				c.push_back((club){i,cost(d[i])});
				s+=tc;
			}
		}
		sort(a.begin(),a.end(),cmp);
		sort(b.begin(),b.end(),cmp);
		sort(c.begin(),c.end(),cmp);
		int mi_a=a[0].v,mi_ai=0,mi_b=b[0].v,mi_bi=0,mi_c=c[0].v,mi_ci=0;
		for(int i=1;i<(int)w.size();i++){
			auto f=w[i];
			if(f.a>=f.b&&f.a>=f.c){
				auto g=d[a[mi_ai].num];
				if(cost(f)>cost(g)){
					a[mi_ai].v=f.a;
					a[mi_ai].num=f.num;
					s+=(cost(f)-cost(g));
					for(int i=0;i<=mi_ai;i++){
						if(mi_a<a[i].v){
							mi_a=a[i].v;
							mi_ai=i;
						}
					}
				}
			}else if(f.b>=f.a&&f.b>=f.c){
				auto g=d[b[mi_bi].num];
				if(cost(f)>cost(g)){
					b[mi_bi].v=f.b;
					b[mi_bi].num=f.num;
					s+=(cost(f)-cost(g));
					for(int i=0;i<=mi_bi;i++){
						if(mi_b<a[i].v){
							mi_b=a[i].v;
							mi_bi=i;
						}
					}
				}
			}else{
				auto g=d[c[mi_ci].num];
				if(cost(f)>cost(g)){
					c[mi_ci].v=f.c;
					c[mi_ci].num=f.num;
					s+=(cost(f)-cost(g));
					for(int i=0;i<=mi_ci;i++){
						if(mi_c<a[i].v){
							mi_c=a[i].v;
							mi_ci=i;
						}
					}
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}