#include <bits/stdc++.h>
using namespace std;
int barrel[15],len;
string s;
char ch;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len = s.size();
	for(int i = 0;i < len;i++){
		ch = s[i];
		if(ch >= '0' && ch <= '9') barrel[(int)(ch-'0')]++;
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= barrel[i];j++) printf("%d",i);
	}
	return 0;
}
