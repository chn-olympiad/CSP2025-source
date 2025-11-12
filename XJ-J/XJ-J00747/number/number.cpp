#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k=1;
	string a;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i];
			k++;
		}
	}
	for(int i=1;i<k;i++){
		for(int j=i+1;j<k;j++){
		if(a[j]>a[i]){
			swap(a[i],a[j]);
		}
	}
	}
	for(int i=1;i<k;i++){
		cout<<a[i];
	}
	return 0;
}
