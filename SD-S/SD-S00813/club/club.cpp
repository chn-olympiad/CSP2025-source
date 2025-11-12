
/*
P      T   zui zhong
1 3    1   1 3
3 4    2   4
2 3    3   2
Õ≈—°»À 

P  T    gongxian
1  1    +4
2  3    +4
3  1 2 3  +5 +3 +4
4  2    +5

1-1
2-3
3-1
4-5


*/ 

#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=1e5+2;
int t,n;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ll ans=0;
		int m=n/2;
		int a[N];
		for(int i=1;i<=n;i++){
			int y,z;
			cin>>a[i]>>y>>z;
			
		}
		sort(a+1,a+1+n);
		for(int i=n;i>n-m;i--){
			ans+=a[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}












