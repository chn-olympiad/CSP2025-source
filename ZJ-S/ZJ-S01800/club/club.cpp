#include <bits/stdc++.h>
#define rint register int
using namespace std;
const int N=1e5+5;
int t,n,a[N][4];
int b[N];
int maxx(rint x){
	return max(a[x][1],max(a[x][2],a[x][3]));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		// init
		memset(b,0,sizeof b);
		// input
		cin>>n;
		for(rint i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		// try
		rint p[4]={0};
		rint s[4]={0};
		for(rint i=1;i<=n;i++){
			if(maxx(i)==a[i][1])p[1]++,s[1]+=a[i][1],b[i]=1;
			else if(maxx(i)==a[i][2])p[2]++,s[2]+=a[i][2],b[i]=2;
			else if(maxx(i)==a[i][3])p[3]++,s[3]+=a[i][3],b[i]=3;
		}
		rint ans=s[1]+s[2]+s[3];
		if(p[1]<=n/2&&p[2]<=n/2&&p[3]<=n/2){
			cout<<ans<<'\n';
			continue;
		}
		// change
		rint x=0;
		for(rint i=1;i<=3;i++)
			if(p[i]>n/2){
				x=i;
				break;
			}
		rint l=(x+1)%3+1;
		rint r=x%3+1;
		priority_queue <int,vector<int>,greater<int> > q;
		for(rint i=1;i<=n;i++)
			if(b[i]==x)q.push(min(a[i][x]-a[i][l],a[i][x]-a[i][r]));
		for(rint i=1;i<=p[x]-n/2;i++){
			ans-=q.top();
			q.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}
