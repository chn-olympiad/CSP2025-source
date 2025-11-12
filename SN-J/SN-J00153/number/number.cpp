#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n= s.size();
	if(n==1){
		cout<<s[0];
		return 0;
	}
	
	for(int i = 0;i < n;i++){
		int c = s[i]-'0';
		if(c >= 0&&c <= 9){
			a[i]=c+1;
		}
	}
	sort(a,a+n);
	for(int i = n;i >= 0;i--){
		if(a[i]>0){
			cout<<a[i]-1;
		}
	}
	return 0;
}
