#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int a[100010];
	int n = 0;
	int c = 0;
	for(int i = 0; i < 20; i++){
		if (s[i] >= '0' && s[i] <= '9'){
			s[i] = s[i]-48;
			a[c] += s[i];
			c++;
	    }
	}
	
	for(int i = 0; i < c; i++){
		for(int j = 0; j < c-i; j++){
			if(a[j] < a[j+1]){
				int b = a[j];
				a[j] = a[j+1];
				a[j+1] = b;
			}
		}
	}
	int x = c;
	for(int i = 0; i < c; i++){
		n+=a[i]*pow(10,x-1);
		x--;
	}
	cout << n;
	
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	

