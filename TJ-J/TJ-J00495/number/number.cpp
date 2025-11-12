#include <bits/stdc++.h>
using namespace std;

bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000001];
	cin >> a;
	int len = strlen(a);
	sort(a,a+len+1,cmp);
	for(int i = 0;i <= len;i ++){
		if( a[i]>='0' && a[i]<='9')
			cout << a[i];
	}
	
	return 0;
}
