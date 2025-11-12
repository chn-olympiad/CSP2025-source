#include<bits/stdc++.h>
using namespace std;
string a;
long long ans[100005],t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9')ans[t++]=a[i]-'0';
	}
	sort(ans,ans+t);
	for(int i=t-1;i>=0;i--){
		cout<<ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}