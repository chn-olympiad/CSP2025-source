#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s[100000]={},c=0;
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		int x=0;
		for(int j=0;j<=9;j++){
			if(a[i]-'0'==j){
				x=1;
			}
		}
		if(x==1){
			s[c]=a[i];
			c++;
			x=0;
		}
	}
	sort(s,s+c,cmp);
	for(int i=0;i<c;i++){
		cout<<char(s[i]);
	}
	return 0;
}

