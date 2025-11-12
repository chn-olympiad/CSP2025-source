// 考号：SN-J01164 姓名：马星辰 学校：西安市曲江第一学校 
#include <bits/stdc++.h>
using namespace std;
int n,m,x,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n*m;i++)
		cin>>a[i];
	x = a[1];
	for (int i = 1;i <= n*m;i++)
		for (int j = 1;j <= n*m-i;j++)
			if (a[j] < a[j+1])
				swap(a[j],a[j+1]);
	for (int i = 1;i <= n*m;i++){
		if (a[i] == x)
			x = i;
		a[i] = i;
	}
	cout<<(x-1)/n+1<<' ';
	if (((x-1)/n+1) % 2 == 1){
		if (x % n == 0)
			cout<<n;
		else
			cout<<x%n;
	}
	else{
		if (x % n == 0)
			cout<<1;
		else
			cout<<n-(x%n)+1;
	}
	return 0;
}
