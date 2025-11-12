#include<bits/stdc++.h>
using namespace std;
int a[1000025];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int o=0;
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++){
		for(int j=0;j<=9;j++){
			if(s[i]-'0'==j){
				a[o]=j;
				o++;
				break;
			}
		}
	}
	sort(a,a+o);
	for(int i=(o-1);i>=0;i--){
        cout << a[i];
	}
	return 0;
} 
