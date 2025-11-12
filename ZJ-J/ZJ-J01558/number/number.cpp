#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],k;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++k]=(int)s[i]-48;
	}
	sort(a+1,a+s.size()+1,cmp);
	for(int i=1;i<=k;i++) cout<<a[i];
	return 0;
}