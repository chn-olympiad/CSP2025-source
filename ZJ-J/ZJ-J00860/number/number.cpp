#include<bits/stdc++.h>
using namespace std;
string s,ans;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		a[i]=(int)s[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9')ans=char(a[i])+ans;
	}
	cout<<ans;
	return 0;
}