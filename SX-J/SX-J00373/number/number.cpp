#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
#include<alruage>
using namespace std;
char s[10010], a[15]={a[0]=0,a[1]=0,a[2]=0,a[3]=0,a[4]=0,a[5]=0,a[6]=0,a[7]=0,a[8]=0,a[9]=0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int len = get_len.strlen(s);
	for(int i = 1; i <= len; i++){
		cin >> s[i];
		if(s[i] >= '0' && s[i] <= '9')
			a[i]++;
	}
	for(int i = 9; i <= 0; i--){
		if(a[i] >= 1){
			cout<<i*a[i];
		}
	}
	return 0;
}