#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.in","r",stdin);
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[ans+1]=0;
			ans++;
		}
		if(s[i]=='1'){
			a[ans+1]=1;
			ans++;
		}
		if(s[i]=='2'){
			a[ans+1]=2;
			ans++;
		}
		if(s[i]=='3'){
			a[ans+1]=3;
			ans++;
		}
		if(s[i]=='4'){
			a[ans+1]=4;
			ans++;
		}
		if(s[i]=='5'){
			a[ans+1]=5;
			ans++;
		}
		if(s[i]=='6'){
			a[ans+1]=6;
			ans++;
		}
		if(s[i]=='7'){
			a[ans+1]=7;
			ans++;
		}
		if(s[i]=='8'){
			a[ans+1]=8;
			ans++;
		}
		if(s[i]=='9'){
			a[ans+1]=9;
			ans++;
		}
	}
	sort(a+1,a+ans+1);
	for(int i=ans;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
