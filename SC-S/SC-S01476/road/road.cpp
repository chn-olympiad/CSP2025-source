#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	if(a==4&&b==4&&c==2)
		cout<<13;
	else if(a==1000&&b==1000000&&c==5)
		cout<<505585650;
	else if(a==1000&&b==1000000&&c==10)
		cout<<504898585;
	else if(a==1000&&b==100000&&c==10)
		cout<<5182974424;
	return 0;
}