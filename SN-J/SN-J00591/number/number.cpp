#include<bits/stdc++.h>
using namespace std;
int a[10],f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int len = s.length();
	for(int i = 0;i <= len-1;i++){
		int num = int(s[i]-'0');
		if(num <= 9){
			a[num]++;
		}
	} 
	for(int i = 9;i >= 1;i--){
		if(a[i] == 0) f=1;
		else{
			f = 0;
			break;
		}
	}
	if(f){
		cout << 0;
	}
	else{
		for(int i = 9;i >= 0;i--){
			while(a[i]>0){
				cout << i;
				a[i]--;
			}
		}	
	}
	return 0;
}
