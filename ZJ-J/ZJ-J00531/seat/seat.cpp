#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
int n,m,ar,a[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//paixu+2fen
	//hao shui,wo zen me gan jue bu yong 2fen dou neng guo lei
	//shi shi zheng ming que shi tai shui le
	//wo zen me huai yi wo kan cuo le bu hui zhen na me shui ba
	cin>>n>>m;
	cin>>ar;
	a[1]=ar;
	for(int i=1;i<n*m;i++){
		cin>>a[i+1];
	}
	sort(a+1,a+n*m+1);
	int i;
	for(i=n*m;i>=0;i--){
		if(a[i]==ar)break;
	}
	i=n*m-i+1;
	int c=i/n,r=0;
	if(i%n!=0)c+=1;
	if(c%2==1 && i%n==0)r+=i%n+n;
	else if(c%2==1 && i%n!=0)r+=i%n;
	else r=n-(i-1)%n;
	cout<<c<<' '<<r;
	return 0;
}
