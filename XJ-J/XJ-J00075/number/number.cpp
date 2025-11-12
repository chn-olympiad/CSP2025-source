#include<iostream>
#include<cstring>
using namespace std;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>=49&&s[i]<=57){
			if(a[int(s[i])-48]==0)
				a[int(s[i])-48]++;
		}
		if(s[i]==48)
			a[0]++;
	}
	for(int i=9;i>=1;i--){
		if(a[i]!=0){
			cout<<i;
		}
	}
	for(int i=1;i<=a[0];i++){
		cout<<0;
	}
	return 0;
}
