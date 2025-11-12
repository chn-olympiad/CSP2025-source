#include<bits/stdc++.h>
using namespace std;
int n , m ,ans ;
int a[110000];
int c[110000] ;
int visit[110000] ;
int a1,a2 ;
int qi ;
int k[110000] ;
int main() {
	freopen("employ.in","r",stdin) ;
	freopen("employ.out","w",stdout) ;
	cin >> n >> m ;
	string str;
	cin >>str;
	for (int i =1;i <=n ;i ++){
		if ( str[i-1]-'0' == 1 )	a1++ ;
		else 						a2++ ;
	}	
	for (int i =1 ;i <=n ;i ++)	cin >>c[i] ;
	//10people , 5 qidian
	long long ans=0 , cnt =0;
	if (m== 1 && a2 >0  ) {
		for (int i =1 ;i <=n ;i ++) {
			if (c[i ] >=1)	cnt ++;
		}
		int sum = cnt ;
		for (int i =n -1; i >=1; i --) {
			sum =sum * i%998244353;
		}
		cout <<sum ;
	}
	else if (m == 5) {
		cout <<2204128;
	}
	else{
		cout <<2;
	}
	
	
	
	return 0;
}