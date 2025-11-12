#include <bits/stdc++.h>
using namespace std;
string a,ans;
int b[1000010],s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l=a.size();
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9')b[++s]=a[i]-'0';
	}
	sort(b+1,b+s+1,cmp);
	for(int i=1;i<=s;i++){
		ans+=(b[i]+'0');
	}
	if(ans[0]=='0'){
		cout<<0;
		return 0;
	}
	l=ans.size();
	for(int i=0;i<l;i++){
		cout<<ans[i];
	}
	return 0;
}
