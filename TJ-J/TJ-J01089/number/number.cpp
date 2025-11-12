#include<bits/stdc++.h>
using namespace std;
string s;
int a[10005];
long long a1=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.length();
	for(long long i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[a1++]=int(s[i]-'0');		
		}
	}
	sort(a,a+a1);
	for(int i=a1-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
