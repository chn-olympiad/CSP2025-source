#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
long long a[2000010],tot=0;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long len=s.length();
	for(long long j=0;j<len;j++){
		if(s[j]>='0'&&s[j]<='9'){
			a[++tot]=int(s[j]-'0');
		}
	}
	sort(a+1,a+tot+1,cmp);
	for(long long j=1;j<=tot;j++){
		cout<<a[j];
	}
	return 0;
}
