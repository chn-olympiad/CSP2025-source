#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[10010],cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=3;j<n;j++){
			int maxn=0,h=0;
			for(int k=i;k<=j;k++){
				maxn=max(maxn,a[k]);
				h+=a[k];
			}
			maxn*=2;
			if(h>maxn){
				cnt++;
			}
		}
	}
	cout<<cnt%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

