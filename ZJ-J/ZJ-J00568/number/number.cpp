#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
bool ok;
int main(){
	freopen("r","number.in",stdin);
	freopen("w","number.out",stdout);
	ok = 0;
	cin>>s;
	for(int i = 0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			
			a[s[i]-'0']++;
		}
	}
	for(int i = 9;i>=0;i--){
		if(a[i]>0&&i!=0){
			ok = 1;
		}
		if(i!=0||ok){
		
			for(int j = 1;j<=a[i];j++){
				cout<<i;
			}
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
