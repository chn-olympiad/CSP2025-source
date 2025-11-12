#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
string s;
int a[N],b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			b++;
			a[b]=int(s[i]-'0');
		}
	}
	sort(a+1,a+b+1);
	for(int i=b;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
