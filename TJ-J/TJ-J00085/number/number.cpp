#include <bits/stdc++.h>
using namespace std;
//求AC 11月对我好点 
string s;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i<s.size();i++){
		if(s[i] >= '0' and s[i] <= '9'){
			a[int(s[i]-'0')]++;
		}
	}
	for(int i = 9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
}
