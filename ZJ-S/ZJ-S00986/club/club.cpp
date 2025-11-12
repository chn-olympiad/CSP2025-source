#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,a[100010][4],ans,q[100010],s;
struct node{
	int c,j;
}p[100010];
bool cmp(node t1,node t2){
  return t1.c<=t2.c;
}
signed main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  cin>>t;
  while(t--){
  	ans=0;
  	cin>>n;
  	for(int i=1;i<=n;i++) {
  		cin>>a[i][1]>>a[i][2]>>a[i][3];
  	    p[i].c=a[i][1]-a[i][2],p[i].j=i;
	  }
	sort(p+1,p+n+1,cmp);
  	for(int i=1;i<=n/2;i++) q[p[i].j]=a[p[i].j][2];
  	for(int i=n/2+1;i<=n;i++) q[p[i].j]=a[p[i].j][1];
  	for(int i=1;i<=n;i++) {
  	    p[i].c=q[i]-a[i][3],p[i].j=i;
	  }
  	sort(p+1,p+n+1,cmp);
  	for(int i=1;i<=n/2;i++){
  		if(p[i].c<0) swap(q[p[i].j],a[p[i].j][3]);
  		else break;
  	}
	for(int i=1;i<=n;i++) {
		ans+=q[i];
	}
  	cout<<ans<<endl;
  }
  return 0;
}
