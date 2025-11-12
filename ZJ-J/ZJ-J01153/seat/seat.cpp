#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[201];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k=0,r,w;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[++k];
	}
	r=a[1];
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			w=i;
		}
	}
	int l=(w-1)/n+1,u=(w-1)%n+1,h;
	if(l%2==0){
		h=n-u+1;
	}
	else{
		h=u;
	}
	cout<<l<<' '<<h;
	
	return 0;
}
