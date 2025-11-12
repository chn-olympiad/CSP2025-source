#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int N=100005;
const int INF=0x3f3f3f3f;
struct Node{
	int a,b,c;
	int mx1,mx2;
}a[N];
bool cmp(Node x,Node y){
	return x.mx1-x.mx2<y.mx1-y.mx2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		int mxc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].mx1=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].mx1==a[i].a) a[i].mx2=max(a[i].b,a[i].c);
			else if(a[i].mx1==a[i].b) a[i].mx2=max(a[i].a,a[i].c);
			else if(a[i].mx1==a[i].c) a[i].mx2=max(a[i].a,a[i].b);
		}
		vector<Node> veca,vecb,vecc;
		for(int i=1;i<=n;i++){
			if(a[i].mx1==a[i].a) veca.push_back(a[i]);
			else if(a[i].mx1==a[i].b) vecb.push_back(a[i]);
			else vecc.push_back(a[i]);
		}
		if((int)veca.size()>n/2){
			sort(veca.begin(),veca.end(),cmp);
			ll ans=0;
			for(auto x:veca) ans+=x.a;
			for(auto x:vecb) ans+=x.b;
			for(auto x:vecc) ans+=x.c;
			for(int i=0;i<(int)veca.size()-n/2;i++) ans-=veca[i].mx1-veca[i].mx2;
			cout<<ans<<"\n";
		}else if((int)vecb.size()>n/2){
			sort(vecb.begin(),vecb.end(),cmp);
			ll ans=0;
			for(auto x:veca) ans+=x.a;
			for(auto x:vecb) ans+=x.b;
			for(auto x:vecc) ans+=x.c;
			for(int i=0;i<(int)vecb.size()-n/2;i++) ans-=vecb[i].mx1-vecb[i].mx2;
			cout<<ans<<"\n";
		}else if((int)vecc.size()>n/2){
			sort(vecc.begin(),vecc.end(),cmp);
			ll ans=0;
			for(auto x:veca) ans+=x.a;
			for(auto x:vecb) ans+=x.b;
			for(auto x:vecc) ans+=x.c;
			for(int i=0;i<(int)vecc.size()-n/2;i++) ans-=vecc[i].mx1-vecc[i].mx2;
			cout<<ans<<"\n";
		}else{
			ll ans=0;
			for(auto x:veca) ans+=x.a;
			for(auto x:vecb) ans+=x.b;
			for(auto x:vecc) ans+=x.c;
			cout<<ans<<"\n";
		}
	}
	return 0;
}

