#include<bits/stdc++.h>
using namespace std;
int z[10];
int a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len-1;i++){
		if(s[i]>='0'&&s[i]<='9')
			z[int(s[i]-'0')]++;
	}
	for(int j=9;j>=0;j--){
		if(z[j]!=0){
			for(int k=z[j];k>0;k--){
				a=a*10+j;
			}
		}
	}
	if(a==0)
		cout<<0;
	else
		cout<<a;
	return 0;
}
