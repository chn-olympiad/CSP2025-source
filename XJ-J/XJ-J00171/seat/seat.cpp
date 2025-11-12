#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n,m,a[N],R,cnt=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m>>R;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>R) cnt++;
	}
	int x=cnt/n,y=cnt%n;
	if(y==0){
		if(x%2==0) y=1;
		else y=n;
		cout<<x<<' '<<y;
		return 0;
	}
	x++;
	if(x%2==0) cout<<x<<' '<<n-y+1;
	if(x%2==1) cout<<x<<' '<<y;
	return 0;
}
