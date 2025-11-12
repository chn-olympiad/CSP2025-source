#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
string j2="",jj2="",ne="";
int temp=0;
int id=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int qz=0,cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(k==a[i]){
				cnt++;
				break;
			}
			qz+=a[j];
			if(qz==k){
				cnt++;
				i=j;
				qz=0;
				break;
			}
			if(qz>k){
				qz=0;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
