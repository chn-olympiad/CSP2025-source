#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	int f=0;
	long long i=0;
	long long num=0;
	while(i<n){
		for(int j=i;j<n;j++){
		    num^=a[j];
			if(num==k){
				cnt++;
				i=j;
				num=0;
				break;
		    }
		}
		i++;
	}
	cout<<cnt;
	return 0;
}
