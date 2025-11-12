#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+100;
string s;
ll a[N],l;
bool flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			if(s[i]!='0')flag=1;
			a[++l]=s[i]-'0';
		}
	}
	sort(a+1,a+1+l);
	if(flag==0){
		cout<<0;
		return 0;
	}
	for(ll i=l;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
