#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),f=0;
	int a[n+2]={};
	for(int i=0;i<n;i++){
		if(s[i]-'0'<=9){
			a[i]=s[i]-'0';
			if(a[i]==0)f++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		if(a[i]==0&&f==0)break;
		cout<<a[i];
		if(a[i]==0)f--;
	}
	fclose(number.in);
	fclose(number.out);
	return 0;
}
