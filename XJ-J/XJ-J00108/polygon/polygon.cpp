#include <bits/stdc++.h>
using namespace std;
int n;
int a,b,c;
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}else{
		cin>>a>>b>>c;
		int num=a+b+c;
		int maxx=2*max(max(a,b),c);
		if(num>maxx){
			cout<<1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
