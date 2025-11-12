#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("xor.in","r",stdin);
	//("xor.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0),cout.tie(0);
	//buhuia*('_')*9595
	int n,k,q=0,p=0;
	cin>>n>>k;
	int a[n],v=0,l=0;
	for(int i=0;i<n;i++){
        cin>>a[i];
	}
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                int k;
            for(int k=1;k<j;k++){
                q=a[k]^a[k-1];
            }
            k++;
            for(;k<j;k++){
                p=a[k]^a[k-1];
            }
            v=max(v,q);
            l=max(l,p);
        }
	}
	cout<<max(v,l)-1;
	return 0;
}
