#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[1000100];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
