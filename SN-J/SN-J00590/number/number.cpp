// 西安市曲江第一学校 SN-J00590 李骏铭
#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int a=s.size();
	int u[a+3]= {0};
	for (int i=0; i<a; i++) {
		if (s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9') {
			if (s[i]=='0') {
				u[n]=0;
			} else if (s[i]=='1') {
				u[n]=1;
			} else if (s[i]=='2') {
				u[n]=2;
			} else if (s[i]=='3') {
				u[n]=3;
			} else if (s[i]=='4') {
				u[n]=4;
			} else if (s[i]=='5') {
				u[n]=5;
			} else if (s[i]=='6') {
				u[n]=6;
			} else if (s[i]=='7') {
				u[n]=7;
			} else if (s[i]=='8') {
				u[n]=8;
			} else if (s[i]=='9'){
				u[n]=9;
			}
				n++;
		}
	}
	sort(u,u+n);
	for (int i=n-1;i>=0;i--){
		cout << u[i];
	}
	cout << endl;

	return 0;
}

