#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000055],p;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("number4.in","r",stdin);
	freopen("number4.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++p]=s[i]-48;
		}	
	}
	sort(a+1,a+1+p);
	for(int i=p;i>=1;i--){
		cout<<char(a[i]+48);
	}
	return 0;
}