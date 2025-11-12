#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int a[N][4];
int T,n,flag;
ll mx1,mx2,ans;
priority_queue<ll>q[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)	
				cin>>a[i][j];
			mx1=mx2=-1,flag=0;
			for(int j=1;j<=3;j++)
				if(a[i][j]>mx1) mx2=mx1,mx1=a[i][j],flag=j;
				else if(a[i][j]>mx2) mx2=a[i][j];
			ans+=mx1;
			q[flag].push(mx2-mx1);
		} 
		for(int i=1;i<=3;i++) 
			while(q[i].size()>(n/2))
				ans+=q[i].top(),q[i].pop();
		cout<<ans<<"\n";
		for(int i=1;i<=3;i++)	
			while(q[i].size()) 
				q[i].pop();
	}
	return 0;
}
