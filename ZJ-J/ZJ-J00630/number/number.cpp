#include<bits/stdc++.h>
using namespace std;
string s;
int a[20],l,f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-48]++;
	for(int i=9;i>=1;i--)
		for(int j=1;j<=a[i];j++){
			cout<<i;
			f=1;
		}
	if(f==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=a[0];i++)
		cout<<0;
}