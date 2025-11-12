#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();++i)
		if(str[i]>='0'&&str[i]<='9') ++num[str[i]-'0'];
	for(int i=9;i>=0;--i)
		for(int j=1;j<=num[i];++j) putchar('0'+i);
	return 0;
}