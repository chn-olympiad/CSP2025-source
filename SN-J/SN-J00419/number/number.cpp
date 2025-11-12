#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[100];
	gets(s);
	int a[100],as=0;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[as]=s[i]-'0';
			as++;
		} 
	}
	sort(a,a+as,cmp);
	for(int i=0;i<as;i++){
		cout<<a[i];
	}
} 
