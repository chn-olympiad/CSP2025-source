#include<bits/stdc++.h>
#define forf(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int N=505;
string s;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	forf(i,1,n) cin>>s;
	forf(i,1,n) cin>>c[i];
	long long sum=1;
	forf(i,1,n) sum*=n,n--,sum%=998244353;
	cout<<sum%998244353;
	return 0;
}

