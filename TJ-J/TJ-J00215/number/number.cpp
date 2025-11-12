#include<bits/stdc++.h>
using namespace std; 
const int N=1e6+10;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int c=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c++;
			a[c]=s[i]-'0';
		}
	}
	sort(a+1,a+c+1,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=c;i++){
		cout<<a[i];
	}
	return 0;
}
