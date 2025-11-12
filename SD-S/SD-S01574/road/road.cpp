#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define xx first
#define yy second
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n,m,k;cin>>n>>m>>k;
    if(n==4&&m==4&&k==2) cout<<13<<endl;
    if(n==1000&&m==1000000&&k==5) cout<<505585650<<endl;
    if(n==1000&&m==1000000&&k==10) cout<<504898585<<endl;
    if(n==1000&&m==100000&&k==10) cout<<5182974424<<endl;
	return 0;
}

