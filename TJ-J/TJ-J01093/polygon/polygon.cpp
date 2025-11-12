#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	sort(a,a+n);
	int N=n;
	for(int i=3;i<=n;i++){
		for(int j=0;j<i;j++){
			N=n;
			int s=0;
			for(int k=j;k<i;k++){
				s+=a[k];
			}
			if(s>2*a[n-i]){
				for(int k=j;k<i;k++){
				    cout<<a[k]<<" ";
		    	}
		    	cout<<endl;
				ans++;
			}
		}
	}
	cout<<ans/998244353;
	return 0;
}
