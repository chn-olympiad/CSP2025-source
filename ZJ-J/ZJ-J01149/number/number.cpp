#include<bits/stdc++.h>
using namespace std;
string s;
int x[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')x[int(s[i]-48)]++;
	}
	for(int i=9;i>=0;i--){
		while(x[i]--)printf("%d",i);
	}
	return 0;
}
//RP++
