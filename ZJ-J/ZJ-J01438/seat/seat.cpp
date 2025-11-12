#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m;
int point;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	point=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==point){
			int x=(i-1)%n+1;
			int y=(i-1)/n+1;
			if(y%2==1)cout<<y<<" "<<x;
			else if(y%2==0)cout<<y<<" "<<n-x+1;
			return 0;
		}
	}
	return 0;
}