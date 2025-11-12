#include<bits/stdc++.h>
using namespace std;
int a[2000000]={0},c=0;
string b;
bool d(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(int i=0;i<b.size();i++){
		if(b[i]>='0'&&b[i]<='9'){
			a[c]=b[i]-'0';
			c++;
		}
	}
	sort(a,a+c,d);
	for(int i=0;i<c;i++){
		cout<<a[i];
	}
	return 0;
}
