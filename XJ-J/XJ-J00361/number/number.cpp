#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	int a[1010];
	int t1=1,max1=-1;
	cin>>s;
	for(int i=1;i<=s.i++){
		if('0'<=s[i]<='9'){
			a[t1++]=s[i];
		}
	}
	sort(a+1,a+1+t1);
	for(int i=1;i<=t1;i++){
		cout<<a[i];
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
