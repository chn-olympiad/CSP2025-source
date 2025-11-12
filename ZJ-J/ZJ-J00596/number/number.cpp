#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;int a[N],len=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9')a[len]=(s[i]-'0'),len++;
	}
	sort(a+1,a+1+len);
	for(int i=len;i>1;i--)cout << a[i];
	return 0;
}
