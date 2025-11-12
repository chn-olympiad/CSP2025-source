#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int m=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			m++;
		}
	}
	int a[m];
	int x=0;
	for(int i=0;i<s.size();i++){	
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i]-48;
			x++;
		}
	}
	sort(a,a+m);
	for(int i=m-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
