#include<bits/stdc++.h>
using namespace std;
int a[1200000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int m=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			m++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<m;i++){
		cout<<a[i];
	}
	
	
	
	return 0;
}
