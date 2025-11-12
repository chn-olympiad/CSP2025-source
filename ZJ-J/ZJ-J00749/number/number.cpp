#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int k=1;

bool cmp(int n,int m){
	return n>m;
}
int main(){
	freopen("number.in","r",in);
	freopen("number.out","w",out);
	string s;
	cin>>s;
	for(int i=0;i < s.size();i++){
		if(s[i]>=48 && s[i]<=57){
			a[k]=s[i]-48;
			k++;
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i <= k-1;i++)  cout<<a[i];
	return 0;
}