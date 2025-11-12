#include<bits/stdc++.h>
#include<string>
using namespace std;
int ans[100005],cnt=0;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9')
		ans[cnt++]=a[i]-48;
	}
	sort(ans,ans+cnt);
	for(int i=cnt-1;i>=0;i--)
	cout<<ans[i];
	return 0;
}
