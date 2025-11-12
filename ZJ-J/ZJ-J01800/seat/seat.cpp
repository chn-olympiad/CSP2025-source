#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],f;
bool com(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	stable_sort(a+1,a+1+n*m,com);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			int y=(i-1)/n+1;
			int x=i-n*(y-1);
			if(y%2==0)x=n-x+1;
			cout<<y<<" "<<x;
			break;
		}
	}
	return 0;
}
