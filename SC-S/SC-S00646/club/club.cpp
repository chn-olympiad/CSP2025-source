#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
struct node{
	int a,b,c,ma,cma;
}q[N];
inline bool operator < (node x,node y){
	return x.ma-x.cma>y.ma-y.cma;
}
inline void solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
	  cin>>q[i].a>>q[i].b>>q[i].c;
	  q[i].ma=max(max(q[i].a,q[i].b),q[i].c);
	  if(q[i].ma==q[i].a)q[i].cma=max(q[i].b,q[i].c);
	  else if(q[i].ma==q[i].b)q[i].cma=max(q[i].a,q[i].c);
	  else q[i].cma=max(q[i].a,q[i].b);
	}
	sort(q+1,q+1+n);
	int cnta=0,cntb=0,cntc=0,sum=0;
	for(int i=1;i<=n;++i){
	  if(q[i].ma==q[i].a){
		if(cnta==(n>>1)){
		  if(q[i].cma==q[i].b){
			++cntb;
			sum+=q[i].cma;
		  }
		  else{
		  	++cntc;
			sum+=q[i].cma;
		  }
		}
		else{
		  ++cnta;
		  sum+=q[i].ma;
		}
	  }
	  else if(q[i].ma==q[i].b){
	  	if(cntb==(n>>1)){
		  if(q[i].cma==q[i].a){
			++cnta;
			sum+=q[i].cma;
		  }
		  else{
		  	++cntc;
			sum+=q[i].cma;
		  }
		}
		else{
		  ++cntb;
		  sum+=q[i].ma;
		}
	  }
	  else{
	  	if(cntc==(n>>1)){
		  if(q[i].cma==q[i].a){
			++cnta;
			sum+=q[i].cma;
		  }
		  else{
		  	++cntb;
			sum+=q[i].cma;
		  }
		}
		else{
		  ++cntc;
		  sum+=q[i].ma;
		}
	  }
	}
	cout<<sum<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}