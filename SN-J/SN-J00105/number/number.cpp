#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010],t = 1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s", s + 1);
	int l = strlen(s + 1);
	for (int i = 1; i <= l; i++) {
		if(s[i]>='0'&&s[i]<='9'){
			a[t] = s[i] - '0';
			t++;
		}
	}
	sort(a+1,a+t);
	for (int i = t-1; i >= 1; i --){
		printf("%d", a[i]);
	}printf("\n");
	return 0;
}
