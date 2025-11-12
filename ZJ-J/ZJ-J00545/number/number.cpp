#include<bits/stdc++.h>
using namespace std;
char a[1000005];
bool cmp(char b,char c){
	return b>c;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>a;
	int n=strlen(a);
	sort(a+0,a+n,cmp);
	for(int i=0;i<n;i++){
		if(a[i]<='9'&&a[i]>='0')cout<<a[i];
	}
	return 0;
}