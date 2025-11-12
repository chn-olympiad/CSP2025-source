#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[100000];
	long long length;
	long long count=0;
	cin>>s;
	length=s.size();
	for(int i=0;i<length;i++){
		if(s[i]=='0' || s[i]=='1' || s[i]=='2'|| s[i]=='3'|| s[i]=='4'|| s[i]=='5'|| s[i]=='6'|| s[i]=='7'|| s[i]=='8'|| s[i]=='9'){
			a[count]=s[i]-'0';
			count++;
		}
	}
	if(count==1)  cout<<a[0];
	else{
		sort(a+0,a+count);
		for(int i=count-1;i>=0;i--){
			cout<<a[i];
		}
	}
	return 0;
} 
