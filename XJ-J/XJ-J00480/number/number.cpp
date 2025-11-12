#include <bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number2.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=int(s[i]-'0');
			n++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
