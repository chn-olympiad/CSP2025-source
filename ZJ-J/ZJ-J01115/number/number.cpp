#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int a,int b){
	if(a>b){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long n=0,m=1;
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[m]=s[i]-'0';
			m++;
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<m;i++){
		cout<<a[i];
	}
	return 0;
}
