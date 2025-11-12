#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	const int N = 1e5+7;
	int t;
	cin >> t;
	while(t--){
		int n,a[N],b[N],c[N];
		int maxn = 0;
		cin >> n;
		int z = n/2;
		for(int i=1;i<=n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		sort(c+1,c+1+n);
		for(int i=n;i>n-z;i--){
			if(i==n-z+1)maxn+=max(a[i],max(b[i],c[i]));
			else maxn=maxn+a[i]+b[i]+c[i];
		}
		cout << maxn << endl;
	}
	
	return 0;
} 
