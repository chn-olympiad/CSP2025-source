#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int c=s.size(),n=0;
	for(int i=0;i<c;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[n++]=s[i]-'0';
		}
	} 
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
