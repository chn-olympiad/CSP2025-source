#include<bits/stdc++.h>
int n=0;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	std::string s;
	std::cin>>s;
	int len=s.length(),a[len];
	for(int i=0;i<len;i++){
		if(s[i]>'0'&&s[i]<='9'){
			a[i]=s[i]-48;
			n++;
		}else if(s[i]=='0'){
			a[i]=0;
			n++;
		}
	}
	for(int i=n;i>=1;i--)for(int j=i;j>=1;j--)if(a[j]>a[j-1])std::swap(a[j],a[j-1]);
	for(int i=0;i<n;i++)std::cout<<a[i];
	return 0;
} 
