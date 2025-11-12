#include<bits/stdc++.h>
using namespace std;
long long n,k,num,a[500025],l,r,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			num=a[j];
			for(int k=j+1;k<i+j;k++){
				num=(num^a[k]);
				if(a[k]==-1){
					num=-2;
					break;
				}
			}
			if(num==k){
				for(int k=j;k<i+j;k++){
					a[k]=-1;
				}
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}