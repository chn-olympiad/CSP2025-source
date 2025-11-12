#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	int k=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0' and s[i]<='9'){
			a[k++]=s[i]-'0';
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
