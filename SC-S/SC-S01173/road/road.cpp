#include<bits/stdc++.h>
using namespace std;
struct e{
	long long f,t,w;
};vector<e> a;
long long fa[10100],n,m,k;
bool cmp(e b,e c){
	return b.w<c.w;
}
int fi(int d){
	if(fa[d]==d){
		return d;
	}else return fa[d]=fi(fa[d]);
}
int co(){
	long long s=0;
	for(int i=0;i<m;i++){
		if(fi(a[i].f)==fi(a[i].t)){
			continue;
		}
		fa[fi(a[i].f)]=a[i].t;
		s+=a[i].w;
		//cout<<i;
	}
	return s;
}
void csh(int k){
	for(int i=0;i<=k;i++){
		fa[i]=i;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	a.clear();
	int tf,tt,tw,c;
	for(int i=1;i<=m;i++){
		cin>>tf>>tt>>tw;
		a.push_back((e){tf,tt,tw});
	}
	sort(a.begin(),a.end(),cmp);
//	for(int i=0;i<a.size();i++){
//		cout<<a[i].w<<' ';
//	}
	csh(n);
	long long s=co(),x=0,rp=0;
	//cout<<s<<endl;
	vector<vector<int> > cd;
	for(int i=0;i<k;i++){
		cin>>c;
		vector<int> t(n);
		for(int i=0;i<n;i++){
			cin>>t[i];
		}
		if(c>s){
			continue;
		}else{
			for(int i=0;i<n;i++){
				a.push_back({n+1,i+1,t[i]});
			}
			sort(a.begin(),a.end(),cmp);
			csh(n+1);
			m+=n;
			int news=co();
			if((news+c)<s){
				cd.push_back(t);
				x++;
			}
			m-=n;
			rp+=c;
		}
	}
	csh(n+x);
	m+=n*x;
	sort(a.begin(),a.end(),cmp);
//	for(int i=0;i<a.size();i++){
//		cout<<a[i].f<<' '<<a[i].t<<' '<<a[i].w<<endl;
//	}
	cout<<co()+rp;
	return 0;
}