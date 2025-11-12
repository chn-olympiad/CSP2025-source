#include<bits/stdc++.h>
using namespace std;
int a[int(5e5+9)];
map<int,int> hash,empty;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,sum=0;
	cin>>n>>k;
	hash[sum^k]=sum;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum^=a[i];
		if(hash.find(sum)!=hash.end()){
			ans++;
			hash=empty;
		}
		hash[sum^k]=sum^k;
	}
	cout<<ans;
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
