#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int k=0;
	int b[10]={0};
	while (a[k]<='z'&&a[k]>='a'||(a[k]<='9'&&a[k]>='0')){
		k++;
	}
	for (int j=0;j<k;j++){
		if (a[j]>='a'&&a[j]<='z'){
			continue;
		}
		b[a[j]-'0']++;
	}
	for (int i=9;i>=0;i--){
		for (int j=0;j<b[i];j++){
			cout<<i;
		}
	}
	return 0;
}
