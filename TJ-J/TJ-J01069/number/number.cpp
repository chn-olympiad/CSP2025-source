#include<bits/stdc++.h>
using namespace std;

string s;
long long int l;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	l = s.length();
	int a[l + 1];
	int cnt = 0;
	for(int i = 0 ; i <= l ; i ++){
		if(s[i] >= '0'  && s[i] <= '9'){
			cnt ++ ;
			a[cnt] = s[i] - 48;
		}
	}
//	for(int i = 1 ; i <= cnt ; i ++){
//		cout << a[i] << " ";
//	}
	sort(a + 1,a + 1 + cnt);
	for(int i = cnt ; i >= 1 ; i --){
		cout << a[i];
	}
	return 0;
}
