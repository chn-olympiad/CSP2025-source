#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int N=1e5+5;
	int x[100005];
	string a;
	int b[N],t=0;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i]=a[i];
			t++;
		}sort(b,b+t);
		for(int i=t;i>=0;i--){
			cout<<b[i];
		}
	}cout<<a;
	return 0;
}

