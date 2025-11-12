#include<bits/stdc++.h>
using namespace std;
int n;
int a,b,c;
int cnt;
int zd;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	cin>>a>>b>>c;
	if(a>=b&&a>=c)zd=a;
	else if(b>=a&&b>=c)zd=b;
	else zd=c;
	if((a+b+c)>zd*2){
		cnt++;
	}cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
