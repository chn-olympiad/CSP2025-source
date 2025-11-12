#include<bits/stdc++.h>
using namespace std;
int a[1000010],b=0;
bool c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			a[b]=(int)(s[i])-48;
			if(a[b]!=0)c=1;
			b++;
		}
	}
	if(c==0){
		cout<<0;
		return 0;
	}
	sort(a,a+b);
	for(int i=b-1;i>=0;i--)cout<<a[i];
	return 0;
}
