//SN-S00712 郭刘天 西安高级中学
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,a,b;
	cin>>n;
	a=n%10;
	b=n/10%10;
	cout<<a+b;
	return 0;
} 
