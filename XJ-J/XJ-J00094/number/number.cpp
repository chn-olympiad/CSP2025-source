#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int num[N];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			num[++len]=int(s[i])-48;
		}
	}
	sort(num+1,num+1+len);
	reverse(num+1,num+1+len);
	for(int i=1;i<=len;i++){
		cout<<num[i];
	}
	return 0;
}
