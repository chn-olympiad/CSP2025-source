#include<bits/stdc++.h>
using namespace std;
char s;
int a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	cin >> s;
	if(s==s){
		cout << s;	
	}
	for(int i=1;i<=s;i++){
		for(int j=1;i<=s;j++){
			if(s>a){
				cout << s;
			}
		}
	}
	return 0;
}
