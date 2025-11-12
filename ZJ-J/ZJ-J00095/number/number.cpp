#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++n]=s[i]-48;
		}
	}
	sort(a+1,a+n+1,greater<int>());
	if(!a[1]){
		cout<<0;
		return 0;	
	}
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}

