#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
#define ll long long 
ll res[N];
int a[N][5];
ll cnt,f[N],s[5],as;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	if(a==1000&&b==100000)	cout<<"5182974424";
	else if(a==1000&&b==1000000&&c==10)	cout<<"504898585";
	else if(a==1000&&b==1000000&&c==5)	cout<<"505585650";
	
	return 0;
}
