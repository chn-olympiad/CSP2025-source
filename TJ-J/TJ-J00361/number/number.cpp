#include <bits/stdc++.h>

using namespace std;
int num[11],cnt;
string a,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for (int i = 0;i < a.size();i++){
		if (a[i] >= '0' && a[i] <= '9'){
			cnt++;
			num[a[i]-'0']++;
		}
	}
	for (int i = 9;i >= 0;i--){
		if (num[i] > 0){
			for (int j = 1;j <= num[i];j++){
				char l = '0' + i;
				ans = ans + l;
			}
		}
	}
	cout << ans;
	return 0;
}
