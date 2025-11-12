#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.length();
	if(len==1){
		cout<<s[0];
		return 0;
	}
	long long ans=0;
	for(int i=0;i<len;i++){
		char x=s[i];
		if(x=='0'){
			a[0]++;
			ans++;
		}else if(x=='1'){
			a[1]++;
			ans++;
		}else if(x=='2'){
			a[2]++;
			ans++;
		}else if(x=='3'){
			a[3]++;
			ans++;
		}else if(x=='4'){
			a[4]++;
			ans++;
		}else if(x=='5'){
			a[5]++;
			ans++;
		}else if(x=='6'){
			a[6]++;
			ans++;
		}else if(x=='7'){
			a[7]++;
			ans++;
		}else if(x=='8'){
			a[8]++;
			ans++;
		}else if(x=='9'){
			a[9]++;
			ans++;
		}
	}
	if(a[0]==ans){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
