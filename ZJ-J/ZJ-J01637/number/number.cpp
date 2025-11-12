#include<bits/stdc++.h>
using namespace std;
string str;
int cnt[100];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int len=str.size();
	str=" "+str;
//	for(int i=1; i<=len; i++)cout<<str[i];
	for(int i=1; i<=len; i++) {
		if(str[i]>='0'&&str[i]<='9')cnt[str[i]-'0']++;
	}
	for(int i=9; i>=0; i--) {
		for(int j=1; j<=cnt[i]; j++)cout<<i;
	}
	return 0;
}

//神兽保佑，代码无 bug !!!

