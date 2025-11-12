#include<bits/stdc++.h>
using namespace std;
int n=1,a[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a+1,a+n);
	for(int i=n-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}