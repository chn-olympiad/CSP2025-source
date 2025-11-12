#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long b[a.size()]={};
	long long n=a.size();
	for(int i=0;i<=a.size()-1;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i]=(int)a[i];
		}
	}
	sort(b,b+n);
	for(int i=n-1;i>=0;i--){
		cout<<(char)b[i];
	}
	return 0;
}
