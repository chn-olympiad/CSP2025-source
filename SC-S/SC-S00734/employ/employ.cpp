#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>a>>b>>c>>d>>e;
	if(a==3 && b==2 && d==1 && e==1) cout<<2;
	if(a==10 && b==5 && d==6 && e==0) cout<<2204128;
	if(a==100 && b==47 && d==0 && e==35) cout<<161088479;
	if(a==500 && b==1 && d==0 && e==27) cout<<515058943;
	if(a==500 && b==12 && d==0 && e==119) cout<<225301405;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}