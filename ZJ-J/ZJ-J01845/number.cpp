#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	int l=0;
	while(s[l]!=0)l++;
	for(int i=0;i<l;i++){
		if(s[i]>=48&&s[i]<=57)a[s[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>0;j--)cout<<i;
	}
	return 0;
}
