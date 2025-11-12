#include<iostream>
using namespace std;
int a[500010],b[1000000];
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n>>k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int idx=0,ans=0;
	for(int l=1;l<=n;l++){
		int sum=a[l];
		if(sum==k){
			if(l>b[idx]){
				b[++idx]=l;
				ans++;
				continue;
			}
		}
		for(int r=l+1;r<=n;r++){
			sum^=a[r];
			if(sum==k){
				if(l>b[idx]){
					b[++idx]=r;
					ans++;
					break;
				}
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
