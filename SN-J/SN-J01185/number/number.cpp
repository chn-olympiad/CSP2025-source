#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[10000],c=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[c]=s[i]-'0';
			c+=1;
		}
	}
	for(int i=0;i<c+1;i++){
		for(int j=0;j<c+1;j++){
			if(a[j+1]>a[j]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<c;i++){
		cout<<a[i];
	}
	return 0;
}
