//CSP-J
//SN-J00313
//张之奇
//西安市铁一中学 

#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
string s;
int cnt;
int a[maxn];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<(int)s.size();i++){
		if (s[i]>='0'&&s[i]<='9')	a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1);
	for (int i=cnt;i>=1;i--)	cout<<a[i];
	return 0;
}
