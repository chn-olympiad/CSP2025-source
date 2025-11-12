#include <bits/stdc++.h>
using namespace std;
int cnt;
bool cmp(int x,int y){
	return x > y;
}
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 0; i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[cnt] = s[i];
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i = 0; i < cnt; i++){
		cout << a[i] - '0';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
