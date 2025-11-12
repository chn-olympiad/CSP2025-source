#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt = 1,R,lie;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> R;
	for(int i = 1;i < n * m;i++){
		long long sb;
		cin >> sb;
		if(sb > R) cnt++;
	}
	if(cnt % n == 0){
		lie = cnt / n;
		cnt = n;
	}
	else{
		lie = cnt / n + 1;
		cnt %= n;
	}
	
	if(lie % 2 == 1) cout << lie << " " << cnt;
	else cout << lie << " " << n - cnt + 1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
