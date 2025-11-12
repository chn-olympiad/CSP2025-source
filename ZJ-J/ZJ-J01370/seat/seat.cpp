#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1);
	int weiz=-1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k) weiz=i;
	}
	int kk=((weiz+n-1)/n)%2;
	if(kk==0){
		cout<<(weiz+n-1)/n<<" "<<n-(weiz%n)+1;
	}else{
		cout<<(weiz+n-1)/n<<" ";
		if(weiz%n==0) cout<<n;
		else cout<<weiz%n;
	}
	return 0;
}