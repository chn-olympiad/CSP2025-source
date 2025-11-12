#include <bits/stdc++.h>
using namespace std;
int a[100005],s[100005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    s[0]=a[0];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	int x=0;
	for(int i=1;i<n;i++){
		s[i]=s[i-1]+a[i];
	 if(i==k&&(s[i]-s[i-k-1])>x) x=s[i-1]-s[i-k-1];
	}cout<<x+1;
    return 0;
}
