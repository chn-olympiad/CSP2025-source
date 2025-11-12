#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt;
int cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i<=s.size();i++){		
		if(char(s[i])-'0'>=0 and char(s[i])-'0'<= 9)a[i] = char(s[i])-'0',cnt++;
	}
	sort(a,a+s.size(),cmp);
	for(int i = 0;i<cnt;i++)cout << a[i];
	return 0;
} 
