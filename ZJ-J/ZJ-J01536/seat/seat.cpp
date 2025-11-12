#include<bits/stdc++.h>
using namespace std;
int n,m,X,seat,a[105],sh[105],sl[105],xa=1;;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	X=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
		if(a[i]==X)seat=n*m-i+1;
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				sh[xa]=j;
				sl[xa]=i;
				xa++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				sh[xa]=j;
				sl[xa]=i;
				xa++;
			}
		}
	}
	cout<<sl[seat]<<" "<<sh[seat];
	return 0;
}