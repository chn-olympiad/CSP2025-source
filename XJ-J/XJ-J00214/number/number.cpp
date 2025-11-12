#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	int a[100005];
	for (int i=1;i <= n;i++){
		if (s[i] = '0')
			a[i] = '0';
		if (s[i] = '1')
			a[i] = '1';
		if (s[i] = '2')
			a[i] = '2';
		if (s[i] = '3')
			a[i] = '3';
		if (s[i] = '4')
			a[i] = '4';
		if (s[i] = '5')
			a[i] = '5';
		if (s[i] = '6')
			a[i] = '6';
		if (s[i] = '7')
			a[i] = '7';
		if (s[i] = '8')
			a[i] = '8';
		if (s[i] = '9')
			a[i] = '9';
	}
	sort(a,a+n);
	for (int i=n-1;i >= 0;i--){
		if (a[i]>=0)
			cout << a;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
