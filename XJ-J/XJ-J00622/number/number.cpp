#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
ll a[N],top=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;//10^6
	for(ll i=0;i<s.size();i++){//10^6
		if(s[i]>='0'&&s[i]<='9'){
			a[top]=s[i]-'0';
			top++;
		}
	}
	//3*10^6+10^7
	top-=1;
	string sum="";
	for(int i=9;i>=0;i--){//10^7
		for(ll j=1;j<=top;j++){
			if(a[j]==i){
				sum=sum+char(a[j]+'0');
			}
		}
	}
	cout<<sum;//10^6
	return 0;
}
