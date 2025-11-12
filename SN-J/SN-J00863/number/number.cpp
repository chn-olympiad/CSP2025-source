//程诺龙轩 SN-J00863 曲江一中 
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
char a[maxn];
string s;
int main(){
//	std::ifstream cin("number.in");
//	std::ofstream cout("number.out");
	cin >> s;
	int len = s.length();
	for(int i = 0; i < len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
		}
	}
	sort(a,a+len);
	for(int j = len; j > -1;j--){
		if(a[j]>='0'&&a[j]<='9')cout << a[j];
	}
	return 0;
}
