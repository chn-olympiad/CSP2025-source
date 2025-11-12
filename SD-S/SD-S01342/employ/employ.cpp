#include<bits/stdc++.h>
using namespace std;
long int f(long int n){
	long long int c=1;
	for(long int i=0;i<n;i++)
		c=c*(n-i);
	return c%9982443583;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long int n,m,ls=0;
	bool fl=1;
	string s;
	cin>>n>>m;
	cin>>s;
	long int r[n]={0};
	for(int i=0;i<s.length();i++){
		if(s[i]='0')	fl=0;
	}
	if(fl==1){
		cout<<f(n);
		return 0;
	}
	for(int i=0;i<n;i++)	cin>>r[i];
	for(int i=0;i<n;i++){
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	return 0;
} 
