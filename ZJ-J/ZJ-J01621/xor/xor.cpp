#include <bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+10;
int a[maxn];
//int xor(int n,int m){
//
//}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int k,n,is_a=1,is_b=1,cnt_1=0,cnt_0=0;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1&&is_a)is_a=0;
		if(a[i]!=0&&a[i]!=1&&is_b)is_b=0;
		if(a[i]==1)cnt_1++;
		if(a[i]==0)cnt_0++;
	}
	if(is_a){
		cout << n/2;
	}
	else if(is_b){
		if(k==1)cout << cnt_1;
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					cnt_0++;
					i++;
				}
			}
			cout << cnt_0;
		}
		return 0;
	}
}