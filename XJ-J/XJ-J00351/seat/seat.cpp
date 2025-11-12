#include <bits/stdc++.h>
using namespace std;
const int N = 15*15;
int a[N],n,m;

bool cmp(int a,int b){
	return a > b;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	 
	cin >> n >> m;
	
	for (int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	
	int R = a[1],num_R=0;
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1;i <= n*m;i++){
		if (a[i] == R)   num_R = i;
	}
	
	int a = 0,b = 0;
	if (num_R % n > 0)   a = num_R / n + 1;
	else   a = num_R / n;
	
	if (a % 2 == 0){
		if ((num_R % n) == 0){
			b = 1;
		}
		else b = n-(num_R % n)+1; 
	}else if (a % 2 == 1){
		if ((num_R % n) == 0){
			b = n;
		}else{
			b = num_R % n;
		}
	}
	cout << a << " " << b;
	return 0;
}
