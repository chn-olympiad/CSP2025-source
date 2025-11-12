#include<bits/stdc++.h>
using namespace std;
string a;
long long b[100005],c=1;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			b[c]=int(a[i]-48);
			c++;
		}
	}
	sort(b+1,b+c,cmp);
	for(int i=1;i<=c-1;i++){
		cout<<b[i];
	}
	return 0;
}
