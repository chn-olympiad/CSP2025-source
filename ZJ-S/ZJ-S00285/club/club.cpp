#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n,a[100004][4],cnt[4],g[100004],ans[100004],x,sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
	  cin>>n;
	  for(int i=1;i<=n;i++)
	    cin>>a[i][1]>>a[i][2]>>a[i][3];
	  memset(cnt,0,sizeof(cnt));
	  memset(g,0,sizeof(g));
	  x=0;
	  sum=0;
	  for(int i=1;i<=n;i++){
	  	g[i]=1;
	  	for(int j=1;j<=3;j++){
	  	  if(a[i][j]>a[i][g[i]])
	  	    g[i]=j;
		}
		cnt[g[i]]++;
		sum+=a[i][g[i]];
	  }
	  int res=1;
	  if(cnt[2]>cnt[res])
	    res=2;
	  if(cnt[3]>cnt[res])
	    res=3;
	  for(int i=1;i<=n;i++){
		if(g[i]==res){
		  x++;
		  ans[x]=1e18;
		  if(res==1)
		    ans[x]=min(ans[x],min(a[i][res]-a[i][2],a[i][res]-a[i][3]));
		  else if(res==2)
		    ans[x]=min(ans[x],min(a[i][res]-a[i][1],a[i][res]-a[i][3]));
		  else
		    ans[x]=min(ans[x],min(a[i][res]-a[i][1],a[i][res]-a[i][2]));
		}
	  }
	  sort(ans+1,ans+1+x);
	  for(int i=1;i<=cnt[res]-n/2;i++)
	  	sum-=ans[i];
	  cout<<sum<<"\n";
	}
	return 0;
}
