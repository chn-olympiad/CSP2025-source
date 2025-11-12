#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			l++;
			a[l]=s[i]-'0';
		}
	}
	sort(a+1,a+l+1,greater<int>());
	for(int i=1;i<=l;i++){
		cout<<a[i];
	}
	return 0;
}