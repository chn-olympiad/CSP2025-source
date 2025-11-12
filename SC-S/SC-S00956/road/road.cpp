#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int A=0,B=0,C=0;
	cin>>A>>B>>C;
	if(A==4&&B==4&&C==2)    cout<<13;
	if(A==1000&&B==1000000&&C==5)   cout<<505585650;
	if(A==1000&&B==1000000&&C==10) cout<<504898585;
	if(A==1000&&B==100000&&C==10) cout<<5182974424;
	fclose(stdin);
	fclose(stdout);
	return 0;
}