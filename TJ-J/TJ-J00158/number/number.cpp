#include <bits/stdc++.h>
using namespace std;
int a[1005]={},l=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[l++]=s[i]-48;
		}
	}
	sort(a+1,a+l,cmp);
	for(int i=1;i<l;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
