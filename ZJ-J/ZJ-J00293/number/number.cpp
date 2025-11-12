#include<bits/stdc++.h>
using namespace std;
string s;
char a[100005];
int summ;
int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	cin >> s;
	for(int i = 0;i < 100005;i++){
		if(s[i] > 'z' || s[i] < '0'){
			break;	
		}
		else{
			if(s[i] >= '0' && s[i] <= '9') a[i] = s[i];
			summ++;
		}
	}
	sort(a,a+summ);
	for(int i = summ-1;i >= 0;i--){
		if(a[i] >= '0' && a[i] <= '9') cout << a[i];
	}
	return 0;
}
