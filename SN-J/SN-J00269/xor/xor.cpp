
//SN-J00269
//安奭颉
//西安高新一中沣东中学初中校区
#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) sum++;
	}
	if(k==0){
		for(int i=2;i<=n;i++){
			if(a[i]+a[i-1]==2){
				sum++;
				i++;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}

