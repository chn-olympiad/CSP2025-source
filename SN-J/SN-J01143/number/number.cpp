//SN-J01143  韩世宇辰  西安辅轮中学   
#include<bits/stdc++.h>
using namespace std;
string s;
int d[1000010],x,n=1;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			d[n]=s[i]-'0';
			n++;
		}
	}
	sort(d+1,d+n+1,cmp);
	for(int i=1;i<n;i++){
		x*=10;
		x+=d[i];
	}
	cout<<x;
	
	return 0;
}
