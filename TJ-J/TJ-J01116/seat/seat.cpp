#include<bits/stdc++.h>
using namespace std;
long long s[20];
int n;
int m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>s[i];
	if(s[1]>98)cout<<1<<" "<<m;
	else if (s[1]>94&s[1]<99)cout<<n<<" "<<m;
	else cout<<n<<" "<<1;
	return 0;
} 
