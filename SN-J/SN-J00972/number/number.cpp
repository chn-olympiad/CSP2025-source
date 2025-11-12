#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),sum=n;
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i]-'0';
			sum--;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=sum;i--){
		cout<<a[i];
	}
	return 0;
}
