#include<bits/stdc++.h>
using namespace std;
int x[1000000],y[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int xn=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			xn++;
			x[xn]=a[i]-48;
		}
	}
	int yn=xn;
	sort(x,x+xn+1);
	for(int i=1;i<=xn;i++){
		y[i]=x[yn];
		yn--;
		cout<<y[i];
	}
	return 0;
}