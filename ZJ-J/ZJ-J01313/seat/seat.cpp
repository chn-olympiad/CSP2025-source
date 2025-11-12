#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+5;
int t,n,m;
struct node{
	int z,wz;
}a[mx];
bool cmp(node x,node y){
	return x.z<y.z;
}
void colse(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].z,a[i].wz=i;
	sort(a+1,a+n*m+1,cmp);
	int bj=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].wz==1){
			bj=n*m-i+1;
			break;
		}
	}
	int _1=(bj+n-1)/n,_2;
	if(_1%2) _2=(bj-1)%n+1;
	else _2=n-(bj-1)%n;
	cout<<_1<<" "<<_2<<endl;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	t=1;
	colse();
	while(t--) solve();
	return 0;
}