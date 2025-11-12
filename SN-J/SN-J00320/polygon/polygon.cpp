#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
const int maxn=5e3+10;
const int inf=1e18;
int n,ans=0;
int a[maxn];
void bfs(int i,int m,int flag,int sum,int maxx){
//	cout<<"i:"<<i<<"  m:"<<m<<"  flag:"<<flag<<"  sum:"<<sum<<"  maxx:"<<maxx<<"  \n";
	if(i==n+1){
		if(m<3){
			return ;
		}
		else{
			if(sum>maxx*2){
				ans++;
//				cout<<"ans:"<<ans;
//				cout<<"\n";
				return ;
			}
			else{
				return ;
			}
		}
	}
	bfs(i+1,m,0,sum,maxx);
	bfs(i+1,m+1,1,sum+a[i],max(maxx,a[i]));
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bfs(1,0,0,0,-inf);
	cout<<ans;
	return 0;
}
//10:24min
