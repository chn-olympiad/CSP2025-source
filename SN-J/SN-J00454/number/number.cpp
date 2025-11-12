#include <bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[i]=-1;
		if(s[i]>='0' && s[i]<='9'){
			a[i]=s[i]-'0';
		}
	}
	int p=0;
	for(int i=0;i<s.size();i++){
		if(a[i]!=-1){
			b[p]=a[i];
			p++;
		}
	}
	sort(b,b+p);
	for(int i=p-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
