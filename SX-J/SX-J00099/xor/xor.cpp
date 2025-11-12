#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num,numg=0;
	cin >> n >> k;
	int a[100000];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	num=a[0];
	for(int j=0; j<n; j++){
		for(int i=j; i<n; i++){
			num=num^a[i];
			if(num==k){
				numg++;
				num=i+1;
				i++;
			}
		}
	}

	cout << numg+1;
	return 0;
}