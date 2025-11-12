#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int c,j=0;
	c=s.size();
	for(int i=0;i<c;i++){
		if(s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9'){
			a[j]=s[i]-'0';
			j++;
		}
			
	}
	sort(a+0,a+j+1);
	for(int i=j;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
