#include <bits/stdc++.h>

using namespace std;

string s,a[1000005];
int f=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0' and s[i]<='9'){
			f++;
			a[f]=s[i];
		}
	}
	sort(a+1,a+1+f);
	for(int i=f;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
