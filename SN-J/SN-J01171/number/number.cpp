#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	int s[20],j = 0;
	cin >> s[20];
	int max = 0;
	max = s[0];
	for (int i = 1;i <= 20;i++){
		if (max < s[i]){
			s[i] = j;
		    s[i] = s[i-1];
		    s[i-1] = j;
		}
	}
	cout << s;
	return 0;
}
