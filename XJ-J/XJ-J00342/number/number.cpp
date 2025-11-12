#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	char b[10001];
	cin>>a;
	int l=a.length(),n=1;
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[n]=a[i];
			n++;
		}
	}
	sort(b+1,b+n+1);
	for(int i=n;i>=1;i--){
		if(b[n]=='0'){
			cout<<"0";
			return 0;
		}
		cout<<b[i];
	}
	return 0;
}
