#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
	string s;
	cin>>s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=1;
	long long ans=0;
	int x=s.size();
	for(int i=0;i<x;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j);
	for(int i=j-1;i>=1;i--){
		ans=ans*10+a[i];
	}
	cout<<ans;
	return 0;
} 
