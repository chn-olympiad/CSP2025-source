#include<bits/stdc++.h>
using namespace std;
float a[1010];
int sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(int i=1;i<=1010;i++){
		a[i]=1.1;
	}
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && '9'>=s[i]){
			a[i]=s[i];
		}
		
	}
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();i++){
			if(a[j]!=1.1){
				a[i]=a[j];
				a[j]=1.1;
				sum++;
			}
		}
		
	}
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}

	fclose(stdin);
	fclose(stdout);
return 0;
}
