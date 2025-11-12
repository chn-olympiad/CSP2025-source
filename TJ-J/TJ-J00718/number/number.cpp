#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s1;
int a[15];
int main(){
	cin>>s1;
	int l=s1.size();
	for(int i=0;i<l;i++)
		if(s1[i]>='0'&&s1[i]<='9') a[s1[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++) printf("%d",i);
	
	
	return 0;
	
} 
