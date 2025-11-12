#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N],ans;
void f(int k,int cnt,int sum,int mx){
	if(k>n){
		if(cnt >= 3 && 2*mx<sum) ans++;
		return;
	}
	int x=a[k];
	f(k+1,cnt+1,sum+x,max(mx,x));
	f(k+1,cnt,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	f(1,0,0,-1);
	cout << ans;
	return 0;
}
