#include<bits/stdc++.h>
using namespace std;
string c;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	int len=c.size();
//	cout<<len<<endl;
	for(int i=0;i<len;++i){
		char t=c[i];
//		cout<<t<<endl;
		if(t>='0'&&t<='9')
			a[t-'0']++;
	}
	for(int i=9;i>=0;--i){
		while(a[i]--)
			cout<<i;
	}
	return 0;
}

