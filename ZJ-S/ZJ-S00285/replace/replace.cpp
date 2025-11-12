#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q;
struct replace{
	string s1,s2;
	ll st,end;
}a[200004];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
	  cin>>a[i].s1>>a[i].s2;
	  int g=a[i].s1.size();
	  bool h=false;
	  for(int j=0;j<g;j++)
	    if(a[i].s1[j]!=a[i].s2[j]){
	      if(!h)
	        a[i].st=j,h=1;
	      a[i].end=j;
	    }
	}
	while(q--){
	  string t1,t2;
	  ll l=0,r=0;
	  cin>>t1>>t2;
	  ll ans=0;
	  if(t1.size()!=t2.size()){
	  	cout<<"0\n";
	  	continue;
	  }
	  int len1=t1.size();
	  bool flag=false;
	  for(int i=0;i<len1;i++){
	  	if(t1[i]!=t2[i]){
	  	  if(!flag)
	  	    l=i,flag=true;
	  	  r=i;
		}
	  }
	  ll p=r-l+1;
	  for(int i=1;i<=n;i++){
	    ll o=a[i].st-1;
	    ll p1=a[i].s1.size()-a[i].st;
	    bool ok=true;
	    ll p2=a[i].end-a[i].st+1;
	    if(p2!=p)
	      continue;
	  	for(int j=-o;j<=p1;j++){
	  	  if(l+j-1<0||l+j-1>=t1.size()){
	  		ok=false;
	  		break;
		  }
	  	  if(a[i].s1[a[i].st+j-1]!=t1[l+j-1]||a[i].s2[a[i].st+j-1]!=t2[l+j-1]){
	  	  	ok=false;
	  	  	break;
		  }
		}
		if(ok==true)
		  ans++;
	  }
	  cout<<ans<<"\n";
	}
	return 0;
}
