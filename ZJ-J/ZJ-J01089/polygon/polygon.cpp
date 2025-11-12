#include<bits/stdc++.h>
using namespace std;

const int N=5010;
int n,a[N],amax;
long long cnt;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		amax=max(amax,a[i]);
	}
	sort(a+1,a+n+1);
	
	if (n==3){
		if (a[1]+a[2]>a[3]){
			cnt++;
		}
		cout<<cnt%998244353;
		return 0;
	}
	if (amax==1){
		for (int j=n-1;j>=1;j--){
			for (int i=j-1;i>=1;i--){
				cnt+=((i*(i+1)/2)%998244353);
			}
		}
		
		cout<<cnt;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}