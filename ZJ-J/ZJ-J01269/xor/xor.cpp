#include<bits/stdc++.h>
using namespace std;
int yh(int a,int b){
	return a^b;
}
int a[500005],s[500005],sum;
bool v[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
    	cin>>a[i];
    	s[i]=yh(s[i-1],a[i]);
	}
	for(int i = 0;i<=n;i++){
		for(int j = 1;j<=n;j++){
			bool f=1;
			for(int k = j;k<=j+i;k++){
				if(v[k]==1){
					f=0;
					break;
				}
			}
			if(f&&yh(s[j-1],s[j+i])==k){
				sum++;
				v[j]=1;
				v[j+i]=1;
			}
		}
	}
	cout<<sum;
	return 0;
} 
