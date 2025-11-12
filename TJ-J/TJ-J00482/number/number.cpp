#include<bits/stdc++.h> 
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[10000010],sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum+=1;
			a[sum]=s[i]-'0';
		}
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		cout<<a[i];
	}
	return 0;
}
