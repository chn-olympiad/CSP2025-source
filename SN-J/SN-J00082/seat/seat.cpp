#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,o,n) for(int i = o;i <= n;i++)
#define dep(i,o,n) for(int i = o;i >= n;i--)
#define mem(x,p) memset(x,p,sizeof x)
const int N = 200;

int a[N];
int o;
int n,m;

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	rep(i,1,n*m) cin>>a[i];
	o=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	rep(i,1,n*m){
		if(a[i]==o){
			int hang = (i+n-1)/n;
			if(hang%2){
				cout<<hang<<" "<<(i-1)%n+1<<endl;
			}else{
				cout<<hang<<" "<<(n-(i-1)%n)<<endl;
			}
		}
	}
}

