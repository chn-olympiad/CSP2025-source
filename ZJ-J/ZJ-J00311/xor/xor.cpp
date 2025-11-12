#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
int a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k,sum=0;
	cin>>n>>k;
	int start=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		for(int j=i;j>=start;j--){
			if(j<=i-1)	x=(x^a[j]);
			if(x==k){
//				cout<<start<<" "<<i<<"\n";	//ÑéÖ¤
				start=i+1; 
				sum++;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
