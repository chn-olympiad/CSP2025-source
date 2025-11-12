#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int r=a[1];
	for(int i=2;i<=m;++i){
		cin>>a[i];
	}
	for(int i=2;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[(i-1)*m+j];
		}
	}
	sort(a+1,a+1+n*m,greater<int>());
	int ok=1;
	int hng=1,lie=1;
	if(a[1]==r){
		cout<<1<<" "<<1<<endl;
	}
	for(int i=2;i<=n*m;++i){
		if(a[i]==r){
			if(hng==1 && ok==-1){
				cout<<lie+1<<" "<<1<<endl;
			}else if(hng+1>n && ok==1){
				cout<<lie+1<<" "<<n<<endl;
			}else{
				cout<<lie<<" "<<hng+1<<endl;
			}
			return 0;
		}
		hng+=ok;
		if(hng<1 && ok==-1){
			hng=1;
			lie++;
			ok=1;
		}else if(hng>n && ok==1){
			hng=n;
			ok=-1;
			lie++;
		}
	}
	return 0;
}
