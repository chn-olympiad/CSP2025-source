#include<bits/stdc++.h>
#define MAXN 9999999
using namespace std;
int a[MAXN];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans++;
			a[ans]=int(s[i])-48;
		}
	}
	sort(a+1,a+ans+1);
	for(int i=ans;i>=1;i--){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
