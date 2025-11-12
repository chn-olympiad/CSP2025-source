#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	ll q=0;
	ll n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
		    q++;
			a[q]=s[i]-48;
		}
	}
	sort(a+1,a+q+1);
	for(int i=q;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}