#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k[10]={0};
	for(int n=0;s[n]!='\0';n++){
		if(s[n]=='0')
			k[0]++;
		if(s[n]=='1')
			k[1]++;
		if(s[n]=='2')
			k[2]++;
		if(s[n]=='3')
			k[3]++;
		if(s[n]=='4')
			k[4]++;
		if(s[n]=='5')
			k[5]++;
		if(s[n]=='6')
			k[6]++;
		if(s[n]=='7')
			k[7]++;
		if(s[n]=='8')
			k[8]++;
		if(s[n]=='9')
			k[9]++;
	}
	long long p=0,ans=0;
	for(int i=0;i<10;i++){
		p+=k[i];
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=k[i];j++){
			ans+=i*pow(10,p-1);
			p--;
		}
	}
	if(ans<0){
		for(int i=9;i>=0;i--){
			for(int j=1;j<=k[i];j++){
				cout<<i;
			}
		}
	}
	else{
		cout<<ans; 
	}
	return 0;
} 
