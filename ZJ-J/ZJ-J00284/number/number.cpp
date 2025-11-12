#include<bits/stdc++.h>
#define ll long long 
using namespace std;
string s;
ll a[1000001];
ll j=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=(int)(s[i]-'0');
			j++;
		} 
	}
	j--;
	if(j==1){
		cout<<a[1];
		return 0;
	}
	sort(a+1,a+1+j);
	for(int i=j;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
