#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500002],l,r,t,f[500002];
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(l=0;l<n;l++){
		t=a[l];
		for(r=l;r<n;t^=a[++r]){
			f[r]=max(f[r],f[r-1]);
			if(t==k){
				f[r]=max(f[r],f[l-1]+1);
				break;
			}
		}
	}
	cout<<f[n-1]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
