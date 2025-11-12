#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,s;
	cin>>a;
	int q=0,w=999999999999;
	for(int i=1;i<=a;i++){
		cin>>s;
		q=max(q,s);
		w=min(q,s);
	}
	cout<<a+q-w;
	return 0;
}
