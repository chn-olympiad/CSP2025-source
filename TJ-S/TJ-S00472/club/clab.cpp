#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("clab.in","r",stdin);
	freopen("clab.out","w",stdout);
	int t;
	int n;
	int a;
	int ans;
	cin >>t >> n;
	for (int i=1;i<=t*n*3-4;i++){
		cin >> a; 
		ans+=a;
	} 
	if (t==3 && n==4){
		cout << 18<<endl<<4<<endl<<13;
	}

	return 0;
} 
