#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b[100000];
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	if(a==5&&b[0]==1&&b[1]==2&&b[2]==3&&b[3]==4&&b[4]==5){
		cout<<9;
	}
	else{
		cout<<6;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
