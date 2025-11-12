#include<bits/stdc++.h>
using namespace std;
string s;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sz=s.size();
	for(int i=0;i<sz;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[int(s[i]-'0')]++;
		}
	}
	for(int j=9;j>=0;j--)
	for(int i=1;i<=a[j];i++)cout<<j;
	return 0;
}
