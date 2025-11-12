#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn];
bool cmp(int n,int m){
	return n>m;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=1;
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(!(s[i]>='0'&&s[i]<='9'))continue;
		a[cnt]=s[i]-'0';
		cnt++;
	}
	sort(a+1,a+cnt,cmp);
	for(int i=1;i<cnt;i++){
		cout << a[i];
	}
}