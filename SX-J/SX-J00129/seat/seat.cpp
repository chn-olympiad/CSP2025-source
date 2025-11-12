#include<bits/stdc++.h>
using namespace std;
int s[1005];
int s2[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	int a1=s[0],k;
	sort(s,s+n*m);
	for(int i=n*m-1;i>=0;i--){
		s2[n*m-i]=s[i];
		if(a1==s2[n*m-i])k=n*m-i;
	}
	if(k%n==0)cout<<k/n<<" "<<n;
	else cout<<k/n+1<<" "<<n-(k%n)+1;
	return 0;
}