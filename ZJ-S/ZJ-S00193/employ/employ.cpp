#include<bits/stdc++.h>
using namespace std;
long long n,m,s;
string st;
int a[1005];
long long f(long long x){
	long long sum=1;
	for(int i=1;i<=x;i++)
		sum*=i;
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>st;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<st.size();i++)
		if(st[i]=='1')
			s++;
	cout<<f(n)-s*s-f(s)+2;
}
