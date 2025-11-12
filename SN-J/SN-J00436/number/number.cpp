#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0;
	char a[1000005];
	string s;
	//cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]<='9'&&'0'<=s[i]){
			a[n]=s[i];
			n++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
	//	cout<<a[i];
	}
	return 0;
}
