#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b[100000];
	int f=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>=48 && a[i]<58){
			b[f]=a[i]-'0';
			f++;
		}
	}
	sort(b,b+f);
	for(int i=f-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}