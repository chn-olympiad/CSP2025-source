#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++) cin >> a[i];
	int t = a[1];
	int num;
	sort(a+1,a+n*m+1);
	for(int i = n*m;i >= 1;i--) if(t == a[i]) num = n * m - i + 1;
	int i = 1,j = 1,cnt = 1;
	while(1){
		if(num == cnt){
			cout << j << ' ' << i;
			break;
		}
		cnt++;
		if(j % 2 == 0){
			if(i == 1) j++;
			else i--;
		}
		else{
			if(i == n) j++;
			else i++;
		}
	}
	return 0;
}

