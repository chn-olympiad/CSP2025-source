#include<bits/stdc++.h>
using namespace std; 
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int a[100005],num=0;
	for(int i=0;i<=n+1;i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			a[num]=int(s[i]);
			num++;
		}
	}
	sort(a,a+num);
	for(int i=num;i>=0;i--){
		if(a[i]>=48&&a[i]<=57){
			cout<<char(a[i]);
		}
	}
	return 0;
}
