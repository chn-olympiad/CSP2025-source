#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+8;
struct node{
  long long x,id;
}s[12];
bool cmp(node o,node p){
  return o.x>p.x;
}
long long t,n,sum,ta,tb,tc,a[N],b[N],c[N];
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  long long i,j,u,v,w,op;
  cin>>t;
  while(t--){
    cin>>n;
    sum=0;
    ta=tb=tc=0;
    for(i=1;i<=n;i++){
      scanf("%lld%lld%lld",&u,&v,&w);
      s[1].x=u;
      s[1].id=1;
      s[2].x=v;
      s[2].id=2;
      s[3].x=w;
      s[3].id=3;
      sort(s+1,s+3+1,cmp);
      op=s[1].id;
      if(op==1){
      	a[++ta]=s[1].x-s[2].x;
	  }
	  if(op==2){
      	b[++tb]=s[1].x-s[2].x;
	  }
	  if(op==3){
      	c[++tc]=s[1].x-s[2].x;
	  }
	  sum+=s[1].x;
    }
	if(ta>n/2){
	  sort(a+1,a+ta+1);
	  for(i=1;i<=ta-n/2;i++){
	  	sum-=a[i];
	  }
	  cout<<sum<<'\n';
	  continue;
	}
	if(tb>n/2){
	  sort(b+1,b+tb+1);
	  for(i=1;i<=tb-n/2;i++){
	  	sum-=b[i];
	  }
	  cout<<sum<<'\n';
	  continue;
	}
	if(tc>n/2){
	  sort(c+1,c+tc+1);
	  for(i=1;i<=tc-n/2;i++){
	  	sum-=c[i];
	  }
	  cout<<sum<<'\n';
	  continue;
	}
	cout<<sum<<'\n';
  }
  return 0;
}/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
