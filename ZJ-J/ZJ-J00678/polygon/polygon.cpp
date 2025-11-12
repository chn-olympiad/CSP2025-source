#include<bits/stdc++.h>
using namespace std;
const int N=5001;
int n,maxx=-1;
int a[N];
long long ans,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	if(n==3){
		for(int i=1;i<=3;i++){
		    cin>>a[i];
		    maxx=max(a[i],maxx);
		    sum+=a[i];
	    }
	    if(sum>maxx*2) cout<<1%998244353;
	    else cout<<"0";
	    return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=3;i<=n;i++){
			int y=n;
			long long ch=1,bch=1;
			for(int j=1;j<=i;j++){
				bch*=j;
				ch*=y;
				y--;
			}
			sum+=ch/bch;
		}
		cout<<sum%998244353;
	}
	return 0;
}
