#include<bits/stdc++.h>
using namespace std;
int a[1000010],n=0,ans=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9')a[n]=str[i]-'0',n++;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		ans*=10,ans+=a[i];
	}
	cout<<ans;
	return 0;
}
