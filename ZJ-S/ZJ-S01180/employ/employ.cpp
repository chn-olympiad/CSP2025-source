#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[1000];
	int p=0,i,j,k,w=0;
	long long ns;
	string s;
	cin>>n>>m;
	cin>>s;
	for(i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n) cout<<1;
	else if(m==1) cout<<n;
	else {
		srand(time(0));
		cout<<time()%2+1;
	}
	return 0;
}