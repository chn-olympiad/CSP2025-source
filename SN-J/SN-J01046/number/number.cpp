#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),m=1;
	int x[100010]={};
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'||s[i-1]=='2'||s[i-1]=='3'||s[i-1]=='4'||s[i-1]=='5'||s[i-1]=='6'||s[i-1]=='7'||s[i-1]=='8'||s[i-1]=='9'||s[i-1]=='0'){
			x[m]=s[i-1];
			m++;
		}				
	}
	sort(x+1,x+m,cmp);
	for(int i=1;i<m;i++){
		cout<<x[i]-48;
	}
	return 0;
}
