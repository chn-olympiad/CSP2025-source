#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 1159764;

int T;
int n;ll ans;
ll dp[nmax][5];
int a[nmax][5];
ll cntbc,cntc;
void dfs(int i,int ca,int cb,int cc,ll now){
	if(i==n+1){
		ans=max(ans,now);
		return;
	}
	
	if(ca<n/2)dfs(i+1,ca+1,cb,cc,now+a[i][1]);
	if(cb<n/2)dfs(i+1,ca,cb+1,cc,now+a[i][2]);
	if(cc<n/2)dfs(i+1,ca,cb,cc+1,now+a[i][3]);
}
ll b[nmax];
struct dd{
	int x,y;
	int cha;
}c[nmax];
int cmp1(dd a,dd b){
	if(a.x!=b.x)return a.x>b.x;
	return a.cha>b.cha;
}
void solve() {
  cin>>n;
ans=0;
  for(int i=1; i <=n; i ++) {
    for(int rp=1; rp<=3; rp++) {
      cin >>a[i][rp];//cout<<a[i][rp]<<" \n"[rp==3];
      //a[i][rp]++;
      
    }
    cntbc+=(a[i][2]+a[i][3]);
    cntc+=(a[i][3]);
  }
  if(cntbc==0){
  	
  	for(int i=1;i <=n;i ++)b[i]=a[i][1];
  	sort(b+1,b+1+n,greater<ll>());
  	for(int i = 1;i <= n/2;i ++)ans+=b[i];
  	cout<<ans<<"\n";
  	return;
  }else if(cntc==0){
  	
  	
  	for(int  i =1;i <= n;i ++){
  		c[i].x=a[i][1];
  		c[i].y=a[i][2];
  		c[i].cha=c[i].x-c[i].y;
	  }
	  
	  sort(c+1,c+1+n,cmp1);
	  int cnta=0;
	  for(int  i =1;i <= n;i ++){
	  	if(c[i].x>c[i].y){
	  		ans+=c[i].x;
	  		cnta++;
	  		c[i].x=0,c[i].y=0;
		  }
		  if(cnta==n/2)break;
	  }
	  for(int i  =1;i <= n;i ++){
	  	if(c[i].x==c[i].y and c[i].x==0)continue;
	  	ans+=c[i].y;
	  }
	   cout<<ans<<"\n";
	   return ;
  }
  
  dfs(1,0,0,0,0);
  cout<<ans<<"\n";
  return;
  cout<<"CSP-S 2025 rp++!";
}
int main() {
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>T;
  while(T--)solve();
  return 0;
}