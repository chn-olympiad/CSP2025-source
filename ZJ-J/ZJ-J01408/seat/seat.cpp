#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1001];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1],wz;
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			wz=i;
			break;
		}
	}
	if(wz%(2*n)<=n&&wz%(2*n)!=0)cout<<2*(wz/(2*n))+1<<" "<<wz%(2*n);
	else if(wz%(2*n)>n)cout<<2*(wz/(2*n))+2<<" "<<2*n-wz%(2*n)+1;
	else cout<<wz/n<<" "<<1;
	return 0;
}
