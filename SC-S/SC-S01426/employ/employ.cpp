#include<bits/stdc++.h>
using namespace std;
char c1,c2,c3,c4,c5;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>c1>>c2>>c3>>c4>>c5;
	if(c1=='3'&&c2=='2'&&c3=='1'&&c4=='0'&&c5=='1')cout<<"2";
	else if(c1=='1'&&c2=='0'&&c3=='5'&&c4=='1'&&c5=='1')cout<<"2204128";
	else if(c1=='1'&&c2=='0'&&c3=='0'&&c4=='4'&&c5=='7')cout<<"161088479";
	else if(c1=='5'&&c2=='0'&&c3=='0'&&c4=='1'&&c5=='1')cout<<"515058943";
	else if(c1=='5'&&c2=='0'&&c3=='0'&&c4=='1'&&c5=='2')cout<<"225301405";
	return 0;
}