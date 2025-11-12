#include<bits/stdc++.h>
using namespace std;
#define N 105
#define int long long

int n,m;
struct node{
	int idx;
	int z;
}a[N];

bool cmp(node x,node y){
	return x.z>y.z;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;++i){
		cin>>a[i].z;
		a[i].idx=i;
	} 
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;++i){
		if(a[i].idx==0){
			int h;
			int l=i/n+1;
			if(l%2==1){
				h=i%n+1;
			}
			if(l%2==0){
				h=n-(i%n);
			}
			cout<<l<<" "<<h;
			return 0;
		}
	} 
	return 0;
}
