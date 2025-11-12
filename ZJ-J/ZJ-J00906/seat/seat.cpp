#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e3+27;

int n,m;
int a[MAXN];

int main() {

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
		cin>>a[i];

	int temp=a[1];

	sort(a+1,a+n*m+1);

	int pos=lower_bound(a+1,a+n*m+1,temp)-a;
	pos=n*m-pos+1;
	
	if(pos%n==0) temp=pos/n;
	else temp=pos/n+1;
	cout<<temp<<" ";
	if((temp)%2==0){
		if(pos%n==0) cout<<1;
		else cout<<n-(pos%n)+1;
	}
	else{
		if(pos%n==0) cout<<n;
		else cout<<pos%n;
	}
	cout<<"\n";

	return 0;
}