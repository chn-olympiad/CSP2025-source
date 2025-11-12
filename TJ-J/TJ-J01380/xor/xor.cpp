#include<bits/stdc++.h>
using namespace std;
int c[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,d=0;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
		if(c[i]==0){
			d++;
		}
	}
	cout<<d;
	return 0;
}
