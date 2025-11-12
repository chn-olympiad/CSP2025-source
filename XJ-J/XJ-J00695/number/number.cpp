#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,js=0;
	char b;
	string s;
	cin >>s;
	n=s.size();
	int a[n+1];
	for(int i=0;i<=n-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			js++;
			a[js]=s[i]-48;
		}
	}
	sort(a+1,a+1+js,cmp);
	for(int i=1;i<=js;i++){
		cout << a[i];
	}
	return 0;
}
