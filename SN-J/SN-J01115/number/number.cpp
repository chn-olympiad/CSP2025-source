#include<bits/stdc++.h>
using namespace std;
int a[10000],m,n;
preopen(number.in,'r',stdin);
preopen(number.out,'w',stdout); 
int main(){
	string s,d; 
	cin >> s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
		{		
		m++;
		d[i]+=s[i];	}
		else continue;
	}
	for(int i=0;i<=d.size();i++){
			a[i]+=(int)d[i]-48;
			n++;
			if(a[i]>a[1]) {
			a[i]==a[1];
			a[1]==d[i];
			}
	}

	for(int i=0;i<=n;i++) 
		cout << a[i];
	return 0;
}
