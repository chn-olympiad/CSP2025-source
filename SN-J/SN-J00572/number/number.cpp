#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("number.in",'w',stdin);
	freopen("number.out",'r',stdout);
	string s;
	cin >> s;
	int len = s.size(); 
	int a[len+1];
	for(int i=0;i < len;i++){
		if(s[i]%1==0){
			a[i] = s[i];
		}
	}
	//sort(a[0],a[len]);
	for(int i=0;i<len;i++){
		cout << a[i] ;
	}
	return 0;
}
