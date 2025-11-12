#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string a;
	int a_=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[a_]=s[i];
			a_++;
		}
	}
	for(int i=0;i<=a_;i++){
		for(int j=i+1;j<=a_;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<a_;i++){
		cout<<a[i];
	}
	return 0;
}
