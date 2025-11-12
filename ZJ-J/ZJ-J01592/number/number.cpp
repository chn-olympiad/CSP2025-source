#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=0;
	for(int i=0; i<s.size(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			l++;
			a[l]=s[i]-'0';
		}
	}
	sort(a+1,a+l+1);
	for(int i=l; i>=1; i--){
		cout<<a[i];
	}
	return 0;
}