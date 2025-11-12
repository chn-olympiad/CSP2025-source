#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=110;
ll n,m;
struct node{
	int val,id;
}a[N];
bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			ll x=i/n;
			if(x*n<i) x++;
			if(x%2==1){
				if(i%n==0) cout<<x<<" "<<n;
				else cout<<x<<" "<<i%n;
			}
			else if(x%2==0){
				if(i%n==1) cout<<x<<" "<<n;
				else if(i%n==0) cout<<x<<" "<<1;
				else cout<<x<<" "<<n-(i%n)+1;
			}
		}
	}
	return 0;
}
