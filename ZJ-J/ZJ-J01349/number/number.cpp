#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt[10] = {0};
	char a[1000010] = {' '};
	scanf("%s",a);
	for(int i = 0;a[i] != ' ';i++){
		if(a[i] >='0'&&a[i] <='9')cnt[a[i] - '0']++;
	}
	for(int i = 9;i >= 0;i--){
		while(cnt[i]--){
			printf("%d",i);
		}
	}
	return 0;
}
