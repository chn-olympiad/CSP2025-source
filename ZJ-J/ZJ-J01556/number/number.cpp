#include<bits/stdc++.h>
using namespace std;
string str;
int a[1000005],n;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> str;
	int len = str.length();
	for(int i = 0; i < len; i++){
		if(int(str[i]) - 48 >= 0 && int(str[i]) - 48 <= 9){
			n++;
			a[n] = int(str[i]) - 48;
		}
	}
	
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++)
		cout << a[i];
	return 0;
}
