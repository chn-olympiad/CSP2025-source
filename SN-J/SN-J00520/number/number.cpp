#include <bits/stdc++.h>
freopen(number.in,'r',strin);
freopen(number.out,'w',strout);
int main{
	string s[1000000];
	string a[9]{1,2,3,4,5,6,7,8,9};
	cin>>s;
	string z[s.size()];
	for(int i=0;i<=s.size()-1;i++){
		for(int j=0;j<=8;j++){
			if(s[i]==a[j]){
				z[i]=s[i];
			}
		}
	}
	int q=10;
	for(int i=0;i<=z.size();i++){
		if(q!=10){
			if(z[i]>q){
				z[i-1]=z[i];
				z[i]=q;
			}
		}
		q=z[i];
	}
	for(int i=0;i<=z.size();i++){
		cout<<z[i];
	}
}
