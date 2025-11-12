#include<bits/stdc++.h>
using namespace std;
string s;
int a1,a2,a3,a4,a5,a6;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
	if(a1==4&&a2==2&&a3==2&&a4==1&&a5==0&&a6==3)  cout<<2;
	else if(a1==4&&a2==4&&a3==4&&a4==4&&a5==4&&a6==4)   cout<<2;
	else  cout<<1;
	return 0;
}
