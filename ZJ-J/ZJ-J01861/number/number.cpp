#include<bits/stdc++.h>
using namespace std;
const int N=1e6+20;
int t,b[N];
string a;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[t]=a[i]-'0';
			t++;
		}
	}
	sort(b,b+t,cmp);
	for(int i=0;i<t;i++){
		cout<<b[i];
	}
	return 0;
}