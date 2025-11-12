#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
bool cmp1(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	int x=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a,a+x,cmp1);
	for(int i=0;i<x;i++){
		cout<<a[i];
	}
	return 0;
}
