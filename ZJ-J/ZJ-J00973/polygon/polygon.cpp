#include<iostream>
#include<algorithm>
using namespace std;
int a[5020]={};
int b[5020][5020]={};
bool f(int a,int b ){
	return a>=b;
}
int mpow(int a){
	int res = 1;
	int t = 2;
	while(a != 0){
		if((a&1)==1)res = (res * t) % 998244353;
		t = (t * t) % 998244353;
		a = a>>1;
	}
	return res;
}
int bb(int n,int m){
	if(n>=0){
		return b[n][m];
	}
	else{
		return mpow(m);
	}
}
int main(){
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n,f);
	//for(int i = 1;i<=n;i++) cout << a[i] << ' ';
	int res = 0;
	for(int i =1;i<=n-2;i++){
		for(int j=1;j<=n-i;j++){
		  b[0][j]=mpow(j) - 1;
	    }
//	    for(int j=1;j<=a[i];j++){
//		  b[j+5010][2]=(a[i+1]+a[i+2]>j)?1:0;
//	    }
	    for(int j=1;j<=a[i];j++){
		  b[j][1]=(a[i+1]>j)?1:0;
	    }
//	    for(int j=10;j<=5010;j++){
//		  b[j][1]=(a[i+1]>j-5010)?1:0;
//	    }
//	    for(int j=10;j<=5010;j++){
//		  b[j][2]=(a[i+1]+a[i+2]>j-5010)?1:0;
//	    }
	    for(int j=1;j<=a[i];j++){
	    	for(int k = 2;k<=n-i;k++){
	    		//b[j][k]=(b[j-1][k]+b[j][k-1]-b[j-1][k-1])  % 998244353;
	    		b[j][k]=(b[j][k-1]+bb(j-a[i+k],k-1))  % 998244353;
			}
		}
		res+=b[a[i]][n-i];
		/*
		for(int i = 0;i<=10;i++){
			for(int j = 0;j<=n;j++){
				cout << b[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/
	}
	
	cout << res;
	return 0;
}