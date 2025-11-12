#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long unll;
using namespace std;
const int N=1e5+100;
int n,m;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int num=0;
	for(int j=1;j<=m;j++){
		for(int i=j&1?1:n;i<=n&&i>0;j&1?++i:--i){
			if(a[++num]==k){
				return cout<<j<<" "<<i<<'\n',0;
			}
		}
	}
	return 0;
}
