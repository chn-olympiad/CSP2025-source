#include<iostream>
#include<algorithm>
char a[10000000];
char b[10000000];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", a);
	int i = 0, m = 0;
	while(a[i] != '\0'){
		if(a[i] >= 48 && a[i] <= 57){
			b[m++] = a[i];
		}
		i ++;
	}
	std::sort(b, b + m, std::greater<int>());
	b[++m] = '\0';
	printf("%s", b);
	return 0;
}
//RP++ >_< AC!!!!!! noWA!!! AK!!!
//RP++ >_< AC!!!!!! noWA!!! AK!!!
//RP++ >_< AC!!!!!! noWA!!! AK!!!
//RP++ >_< AC!!!!!! noWA!!! AK!!!
