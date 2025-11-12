#include<bits/stdc++.h>
using namespace std;
string s;
int nu[20] = {};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l = s.length();
	s = " " + s;
	for(int i = 1;i <= l;i++){
		if(s[i] <= '9' && s[i] >= '0'){
			//is the number
			nu[s[i] - 48] ++;
		}
	}
	for(int i = 15;i >= 0;i--){
		if(nu[i]){
			for(int j = 1;j <= nu[i];j++)printf("%d",i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
