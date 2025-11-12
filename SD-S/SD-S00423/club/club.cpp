#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int p[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout);
	int m=0;
	int t,n,a,x,y,ans=0,ans1=0,cnt=0,renshu=0,a1=0,x1=0,y1=0;
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		for(int i=0;i<n;i++){
			cin>>a>>x>>y;
			if(a>x&&a>y){
				a1++;
				ans+=a;
			}else if(x>a&&x>y){
				x1++;
				ans+=x;
			}else if(y>a&&y>x){
				y1++;
				ans+=y;
			}
			if(a1>m){
				ans-=a;
				if(x1<m){
					ans+=x;
					continue;
				}else if(y1<m){
					ans+=y;
					continue;
				}
			}
			//
			if(x1>m){
				ans-=x;
				if(a1<m){
					ans+=a;
					continue;
				}else if(y1<m){
					ans+=y;
					continue;
				}
			}
			if(y1>m){
				ans-=y;
				if(a1<m){
					ans+=a;
					continue;
				}else if(x1<m){
					ans+=x;
					continue;
				}
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
/*
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
//[N][N]
