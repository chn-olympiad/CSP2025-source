#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],n=0;

int main(){
	feropen("numder.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.length();
	for(int i = 1;i <= len; ++i){
		if(s[1] >= '0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			n++;
		}
	}
	sort(a+1,a+n+1);
	for(int j = n;j > 0; --j){
		cout << a[j];
	}
	return 0;
}s
