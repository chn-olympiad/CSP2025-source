#include<bits/stdc++.h>
using namespace std;
string s;
int a[114514];
int maxn=INT_MAX;
int main(){
	freopen("number.in","r","stdin");
	freout("number.out","w","stdout");
	getline(cin,s);
	for (int i=0; i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9'){
			cout << s[i];
		}
	} 
return 0;
}
