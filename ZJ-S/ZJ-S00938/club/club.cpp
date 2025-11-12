#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
const int N=1e5+5;
int n;
struct node{
	int a,b,c;
}ns[N];
bool cmpA(node x,node y){return x.a-max(x.b,x.c)<y.a-max(y.b,y.c);}
bool cmpB(node x,node y){return x.b-max(x.a,x.c)<y.b-max(y.a,y.c);}
bool cmpC(node x,node y){return x.c-max(x.a,x.b)<y.c-max(y.a,y.b);}
void solve(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>ns[i].a>>ns[i].b>>ns[i].c;
	int numa=0,numb=0,numc=0;
	long long res=0;
	vector<node>pa,pb,pc;
	for(int i=1;i<=n;++i){
		if(ns[i].a>=max(ns[i].b,ns[i].c)){
			++numa;
			res+=ns[i].a;
			pa.push_back(ns[i]);
		}
		else if(ns[i].b>=max(ns[i].a,ns[i].c)){
			++numb;
			res+=ns[i].b;
			pb.push_back(ns[i]);
		}
		else if(ns[i].c>=max(ns[i].a,ns[i].b)){
			++numc;
			res+=ns[i].c;
			pc.push_back(ns[i]);
		}
	}
	if(numa<=n/2&&numb<=n/2&&numc<=n/2){
		cout<<res<<endl;
	}
	else{
		if(numa>n/2){
			sort(pa.begin(),pa.end(),cmpA);
			for(int i=0;numa>n/2;++i){
				res-=pa[i].a;
				res+=max(pa[i].b,pa[i].c);
				--numa;
			}
		}
		else if(numb>n/2){
			sort(pb.begin(),pb.end(),cmpB);
			for(int i=0;numb>n/2;++i){
				res-=pb[i].b;
				res+=max(pb[i].a,pb[i].c);
				--numb;
			}
		}
		else if(numc>n/2){
			sort(pc.begin(),pc.end(),cmpC);
			for(int i=0;numc>n/2;++i){
				res-=pc[i].c;
				res+=max(pc[i].a,pc[i].b);
				--numc;
			}
		}
		cout<<res<<endl;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	IOS;
	int _;cin>>_;
	while(_--)solve();
	return 0;
}