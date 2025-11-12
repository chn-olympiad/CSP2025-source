#include <bits/stdc++.h>
using namespace std;
char num[1000010];
int j=1;
int main(){
	freopen("number1.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.size();++i){
		if('0'<=s[i] && s[i]<='9'){
			num[j]=s[i];
			++j;
		}
	}
	sort(num+1,num+j+1);
	for(int i=j;i>0;--i){
		cout<< num[i];
	}
	return 0;
}

