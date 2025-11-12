#include<bits/stdc++.h>
using namespace std;
int k[100] ;
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out" , "w" , stdout);
	string str;
	cin >> str;
	int len = str.size() ;
	
	int n = 0;
	for (int  i = 0;i < len ;i ++) {
		if (str[i] <='9' && str[i] >='0' )	{
			k[ str[i] - '0' ] ++ ;
		}
	}
	
	for (int i =9 ;i >=0 ;i --) {
		for (int j =1 ;j<=k[i] ; j ++){
			cout <<i;
		}
	}
	
	
	return 0;
}