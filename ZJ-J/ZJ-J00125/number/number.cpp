#include<bits/stdc++.h>
using namespace std;
string a;
int x[1005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int id=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			x[++id]=a[i];
		}
	}
	sort(x+1,x+id+1,cmp);
	if(x[1]-'0'==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=id;i++){
		cout<<x[i]-'0';
	}
	return 0;
}
