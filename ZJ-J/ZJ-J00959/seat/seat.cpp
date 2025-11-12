#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int num = 1;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
		if(a[i] > a[1]) num++;
	}
	int x,y = (num+n-1)/n;
	if(y % 2 == 0) x = n-((num-1)%n+1)+1;
	else x = ((num-1)%n+1);
	cout << y << ' ' << x;
	return 0;
}
