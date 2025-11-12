#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0') a[cnt++]=s[i]-'0';
	}
	sort(a+1,a+cnt);
	for(int i=cnt-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
