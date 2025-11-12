#include <iostream>
using namespace std;
int n,k,a[500010],b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			a[i]=a[i]^a[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((a[j]^a[i-1])==k){	
				b[i]=j;
				break;
			}
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		if(b[i]){
			mx++;
			i+=b[i]-i;
		}
	}
	cout<<mx;
	return 0;
}

