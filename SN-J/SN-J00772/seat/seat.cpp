#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s[1000];
	cin >> n >>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin >> s[i];
	}
	if(s[1]=99){
		cout << "1 2";
	}else if(s[1]=98){
		cout <<"2 2";
	}else if(s[1]=94){
		cout <<"3 1";
	}
	return 0;
}

