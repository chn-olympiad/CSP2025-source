#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[10005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char q;
	int m = 0;
	scanf("%d",&q);
	if(q == 5){
		printf("5");
		return 0;
	}
	for(int i = 0;;i++){
	
		if(q / 10 <= 'z' && q/10>= 'a'){
			++i;
		}
		a[i] = q%10;
		q/=10;
		if(q == 10){
			break;
		}
		m++;
	}
	for(int i = 0;i <= m;i++){
		for(int j = 0;j <= i;j++ ){
			if(a[i]> a[j])
			{
				q = a[i];
				a[i] = a[j];
				a[j] = q;
			}
		}
	}
	for(int i = 0;i <= m;i++){
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
