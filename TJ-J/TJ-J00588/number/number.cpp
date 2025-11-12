#include<bits/stdc++.h>
using namespace std;
string s;
int a[1111111]={0};
bool cmp(int a,int b){
	return b<a;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int l=s.size();
	int k=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++){
		if(a[i]>='0'&&a[i]<='9'){
			cout<<a[i]-'0';
			continue;
		}
		cout<<a[i];
	}
	return 0;
}
