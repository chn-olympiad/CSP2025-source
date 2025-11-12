#include <bits/stdc++.h>
using namespace std;
const int NB=5e5+5;
int n,k,a[NB],tjxor[NB];
int main(void)
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		tjxor[i]=tjxor[i-1]^a[i];
	}
	int tpos=0,tans=0;
	for(int i=1;i<=n;i++) {
		int tmpp=tpos;
		for(int j=tmpp;j<i;j++) {
			int rres=tjxor[i]^tjxor[j];
			if(rres==k) {
				tans++;
				tpos=i;
				break;
			}
		}	
	}
	cout<<tans;
	return 0;
} 
