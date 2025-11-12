#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
char s[N];
int a[N],xb=1;
bool cmp(int aaa,int bbb){
	return aaa>bbb;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[xb]=s[i]-'0';
			xb++;
		}
	}
	sort(a+1,a+xb,cmp);
	for(int i=1;i<xb;i++) cout<<a[i];
	return 0;
} 
