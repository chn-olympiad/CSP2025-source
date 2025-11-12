#include<bits/stdc++.h>
using namespace std;
long long a,b,c[100000],d;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
		if(c[i]==b){
			d++;
			c[i]=-1;
		}
	}
	cout<<d;
	return 0;
}