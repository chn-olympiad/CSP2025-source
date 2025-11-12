#include <bits/stdc++.h>

using namespace std;
long long t,n,n2,a[5][100005],a1[100005],a2[100005],a3[100005],a12[100005],a13[100005],a23[100005],a123[100005],b[5]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		n2 =n/2;
		for(int i = 1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			a12[i]=a12[i-1]+max(a[1][i],a[2][i]);
			a13[i]=a13[i-1]+max(a[1][i],a[3][i]);
			a23[i]=a23[i-1]+max(a[2][i],a[3][i]);
			a123[i]=a123[i-1]+max(a[1][i],max(a[2][i],a[3][i]);
		}
		long long mx = max(a12[n],max(a13[n],max(a23[n],a123[n]))); 
		cout<<mx<<endl;
	}
	return 0;
} 
