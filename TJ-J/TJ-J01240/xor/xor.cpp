#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x=0,ans=0,last=0;
	cin >> n >> k;
	for(int i=0,a;i<n;i++){
	    cin >> a;
		x^=a;
		if(x==k || (last ^ x)==k){
			ans++;
			x=0;
			last=0;
		
		}
		else{
			last=x;
		}
	}
	cout << ans << endl;
	return 0;
}
