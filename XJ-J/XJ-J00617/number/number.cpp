#include <bits/stdc++.h>
using namespace std;
bool STD(int x,int y){
	return x>y;
}
int main(){
	string s;
	freopen("number.in","R",stdin);
	freopen("number.out","W",stdout);
	int sw[9999],j=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-48<10 && s[i]-48>=0){
			sw[j]=s[i]-48;
			j++;
		}
	}
	sort(sw,sw+j,STD);
	for(int i=0;i<j;i++){
		cout<<sw[i];
		
	}
	return 0;
}
