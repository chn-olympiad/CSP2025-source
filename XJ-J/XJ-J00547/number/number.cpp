#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int l,t[N],h;
string a;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	l=a.size();
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			t[++h]=a[i]-'0';
		}
	}
	sort(t+1,t+1+h,cmp);
	if(h==0||t[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=h;i++){
		cout<<t[i];
	}
	
	return 0;
}
