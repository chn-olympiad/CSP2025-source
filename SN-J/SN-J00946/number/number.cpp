#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){
	return x > y;
}
int num[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int c = 0;
	for (int i=0; i<s.length(); i++){
		if (isdigit(s[i])){
			num[c++] = s[i]-'0';
		}
	}
	sort(num,num+c,cmp);
	for (int i=0; i<c; i++){
		cout << num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
