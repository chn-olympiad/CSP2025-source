#include<bits/stdc++.h>
using namespace std;
string s;
char c;
int a[1000005],b=-1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		c=s[i];
		if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'){
			b++;//bÊÇÎ»Êý 
			a[b]=c-'0';
		}
	}
	sort(a,a+b+1);
	for(int i=b;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
