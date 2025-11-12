#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
bool cmp(char cc,char ccc){
	return cc>ccc;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for (int i=0;i<1000005;i++)a[i]=2;
	for (int i=0;i<l;i++)if ('0'<=s[i] && '9'>=s[i])a[i]=s[i];
	sort(a,a+l,cmp);
	if (a[0]=='0'){
		cout<<0;
		return 0;
	}
	for (int i=0;i<l;i++)if ('0'<=a[i] && '9'>=a[i])cout<<a[i];
	return 0;
} 
