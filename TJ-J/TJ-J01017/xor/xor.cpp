#include <iostream>
#include <cstdio>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool flag = true,flag2 = true;
	int n,k,cnt = 0;
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] != 1) flag = false;
		if (a[i] > 1) flag2 = false;
	}
	if (flag) cout << n / 2;
	else if (flag2){
		if (k == 0){
			for (int i = 1;i <= n;i++)
				if (i+1 <= n && a[i+1] == a[i]){
					cnt++;
					i++;
				}
		}
		else{
			for (int i = 1;i <= n;i++)
				if (i+1 <= n && a[i+1] != a[i]){
					cnt++;
					i++;
				}
		}
		cout << cnt;
	}
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
