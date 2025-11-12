#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005],top;
bool flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.length();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++top]=a[i]-'0';
		}
	}
	sort(b+1,b+top+1);
	for(int i=top;i>=1;i--){
		if(b[i]!=0||flag){
			cout<<b[i];
			flag=true;
		}
	}
	if(!flag){
		cout<<0<<endl;
	}
	return 0;
}
