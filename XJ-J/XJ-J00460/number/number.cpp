#include <bits/stdc++.h>
using namespace std;
string s;
int arr[1000006];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int xb=1;
	for(int i = 0; i < s.size(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[xb++]=s[i]-'0';
		}
	}
	sort(arr+1,arr+xb);
	for(int i = xb-1; i >= 1; i--){
		cout << arr[i];
	}
	return 0;
}
