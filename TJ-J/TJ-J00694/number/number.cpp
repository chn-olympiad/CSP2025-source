#include <bits/stdc++.h> 
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int len = s.size();
	int j = 0;
	for(int i = 0;i < len;i++){
		if(s[i] == '1'){
			a[j++] = 1;
		}else if(s[i] == '2'){
			a[j++] = 2;
		}else if(s[i] == '3'){
			a[j++] = 3;
		}else if(s[i] == '4'){
			a[j++] = 4;
		}else if(s[i] == '5'){
			a[j++] = 5;
		}else if(s[i] == '6'){
			a[j++] = 6;
		}else if(s[i] == '7'){
			a[j++] = 7;
		}else if(s[i] == '8'){
			a[j++] = 8;
		}else if(s[i] == '9'){
			a[j++] = 9;
		}else if(s[i] == '0'){
			a[j++] = 0;
		}
	}
	sort(a,a+j);
	for(int i = j - 1;i >= 0;i--){
		cout << a[i];
	}
}
