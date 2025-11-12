//	SN-J00234  姚棕严  西安市曲江第一中学

#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>s;
	
	int l=s.size(),j=0;
	
	for(int i=0;i<=l-1;i++){
		if(s[i]>=48 && s[i]<=57){
			j++;
			a[j]=int(s[i])-48;
		}
	}
	
	sort(a+1,a+j+1);
	
	for(int i=j;i>0;i--){
		cout<<a[i];
	}
	
	return 0;
}
