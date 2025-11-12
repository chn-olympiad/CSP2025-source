#include <bits/stdc++.h>
using namespace std;
char s[1000001];
int a[1000001];
int main(){
	freopen("number.in","r", stdin);
	freopen("number.out","w", stdout);
	int n = 0;
	scanf("%s", s + 1);
	int l = strlen(s + 1);//长度 
	for(int i = 1; i <= l; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			n++;
			a[n] = s[i] - 48;
		}
	}
	//提取数字 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[j] < a[j + 1]){
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				
			}
		}
	}//排序
	for(int i = 1; i <= n; i++){
		cout << a[i];
	}//输出 
	return 0;
}
