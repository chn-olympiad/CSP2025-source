#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string b;
bool cmp(int x,int y){
	return y<x;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	int js=0,sj=0;
	for(int i=0;i<b.size();i++){
		if(b[i]>='0'&&b[i]<='9'){
			a[i]=int(b[i]-'0');
		}else{
			sj++;
		}
	}
	sort(a,a+b.size(),cmp);
	for(int i=0;i<b.size()-sj;i++){
		cout<<a[i];
	}
	return 0;
}
