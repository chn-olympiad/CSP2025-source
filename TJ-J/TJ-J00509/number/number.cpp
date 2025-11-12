#include<bits/stdc++.h>
using namespace std;
int a[1000060];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),x=0;
	for(int i=0;i<n;i++){
		if(isdigit(s[i])){
			a[x]=s[i]-48;
			x++;
		}
	}
	sort(a,a+x);
	for(int i=x-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
