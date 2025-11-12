#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000000];
long long t=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i];
			t++;
		} 
	}
	sort(a,a+t);
	if(a[t-1]=='0'){
		cout<<0;
	} 
	else{
		while(t>=0){
			cout<<a[t-1];
			t--;
		}	
	}
	return 0;
}
