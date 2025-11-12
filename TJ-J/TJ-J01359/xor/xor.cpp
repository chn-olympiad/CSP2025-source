#include<bits/stdc++.h>
using namespace std;
int n,k;
int t[100001];
int sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>t[i];
	}
	int temp=0;
	for (int i=1;i<=n;i++){
		if (t[i]==k){
			sum++;
			continue;
		}
		temp=t[i];
		for (int j=i+1;j<=n;j++){
			temp=t[j]|temp;
			if (temp==k){
				//for (int k=X;k<=j;k++){
				//	F[k]=1;
				//}
				sum++;
				//X=j;
				i=j;
				//cout<<temp<<" "<<t[j]<<endl;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
