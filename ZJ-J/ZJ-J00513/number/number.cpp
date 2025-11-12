#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.size(), tmp = 0;
	for(int i = 0;i < len;i ++)
		if(s[i] >= '0' && s[i] <= '9')a[++tmp] = s[i] - '0';
	sort(a+1,a+tmp+1);
	for(int i = tmp;i > 0;i --){
		printf("%d",a[i]);
	}
	return 0;
}
