#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int num[10]={0};
	cin>>a;
	for(int i=0;i<a.size();i++)
		if(a[i]>='0'&&a[i]<='9')
			num[a[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(num[i]--) cout<<i;
} 
