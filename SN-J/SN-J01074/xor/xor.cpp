#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,k,a[500005],ans[250000][2],anse;
int main(){
	freopen("xor1.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int xo,num=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			ll xo=a[i];
			for(int h=i+1;h<=j;h++){
				xo=xo^a[h];
			}
			if(xo==k){
				ans[num][0]=i;
				ans[num][1]=j;
				num++;
			}
		}
	}
	
	cout<<num;
	return 0;
} 
