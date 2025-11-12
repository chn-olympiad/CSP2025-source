#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,now,t=0,j=1;
int a[15];
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
	now=a[1];
	sort(a+1,a+n*m+1,cmp);
	if(a[1]==now){
		cout<<1<<" "<<1;
		return 0;
	}
	while(true){
		for(int i=1;i<=n;i++){
			t++;
			if(a[t]==now){
				cout<<j<<" "<<i;
				return 0;
			}
		}
		j++;
		for(int i=n;i>=1;i--){
			t++;
			if(a[t]==now){
				cout<<j<<" "<<i;
				return 0;
			}
		}
		j++;
	}
	return 0;
}