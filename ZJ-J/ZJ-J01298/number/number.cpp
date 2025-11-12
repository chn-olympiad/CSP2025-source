#include <bits/stdc++.h>
using namespace std;
int a[10000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int k=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	for(int i=1;i<=k;i++){
		cout<<a[k-i+1];
	}
	return 0;
}
