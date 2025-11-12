#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000010], o = 1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	int len = a.size();
	for (int i = 0; i <= len; i ++)
		for (int j = 0; j <= 9; j ++)
			if (a[i] - '0' == j){
				b[o] = j;
				o ++;
				break;
			}
	sort(b + 1, b + o);
	for (int i = o - 1; i >= 1; i --)cout << b[i];
	return 0;
} 
