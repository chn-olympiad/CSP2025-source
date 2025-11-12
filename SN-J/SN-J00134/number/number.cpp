// SN-J00134  刘浩辰  西安高新一中沣东中学 

#include <bits/stdc++.h>

using namespace std;

char a[1000005]; 
 
int cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("D:/SN-J00134/number/number.in","r",stdin);
	freopen("D:/SN-J00134/number/number.out","w",stdout);
	

	string s;
	cin >> s;
	int len = s.size();
	for(int i = 0;i < len;++i){
		if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
			a[i] = s[i];
		}
	}
	sort(a,a+len,cmp);
	for(int i = 0;i < len;++i)
		cout << a[i]; 
	return 0;
}
