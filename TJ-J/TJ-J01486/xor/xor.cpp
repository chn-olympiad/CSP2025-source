#include <bits/stdc++.h>
using namespace std;
unsigned int a[600005]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	unsigned int n,k,cnt=0,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=0;
//		cout<<"i:"<<i<<endl;
		for(int j=i;j<=n;j++){
//			cout<<"j:"<<j<<endl;
			cnt=cnt^a[j];
			if(cnt==k){
//				cout<<i<<"    "<<j<<endl;
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
