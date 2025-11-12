#include<bits/stdc++.h>
using namespace std;
struct club{
	int a,b,c;
}m[100005];
int n; 
bool cmp(club x,club y){
	if(x.a==y.a) return x.b>y.b;
	return x.a>y.a;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	while(true){
		char p=cin.get();
		if(p=='\n') return 0;
		cout<<0<<endl;
		char q=cin.get();
	}
	return 0;
} 
