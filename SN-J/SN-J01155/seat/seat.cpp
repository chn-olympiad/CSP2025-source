#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
		b[i] = a[i];
	}
	sort(a+1,a+n*m+1);
	int flag = 0;
	for(int i = 1;i<=m*n;i++){
		flag++;
		if(a[i] == b[1]){
			break;
		}
	}
	flag = m * n - flag + 1;
	int x = flag / m + 1;
	int y;
	if(flag % m == 0){
		x = flag / m;
		y = n - flag % m;
	}
	else{
		if(x % 2 != 0) y = flag % m;
		else y = n - flag % m + 1;
	}
	cout<<x<<" "<<y;
	return 0;
}
