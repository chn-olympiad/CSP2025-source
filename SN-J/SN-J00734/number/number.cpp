#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MA=1e6+10;
int a[MA];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int n=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++n]=(s[i]-'0');
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) cout<<a[i];
	return 0;
}

