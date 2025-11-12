#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int m=s.size(),n=0;
	s=" "+s;
	for(int i=1;i<=m;i++){
		if(s[i]<='9'&&s[i]>='0') a[++n]=s[i]-'0';
	}
	sort(a+1,a+1+n,cmp);
	int st=1;
	while (a[st]==0&&st<n) st++;
	for(int i=st;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}