#include<bits/stdc++.h>
using namespace std;
string t;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	for(int i=0;i<t.size();i++){
		if(t[i]>='0'&&t[i]<='9'){
			a[t[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
