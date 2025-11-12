#include<bits/stdc++.h>
using namespace std;
int a[500010];
bool b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			b[i]=1;
//			cout<<i<<" "<<i<<endl;
		}
	}
	for(int i=0;i<n;i++){
		if(!b[i]){
			int q=a[i],lef=i,rig=i;
			for(int j=i+1;j<=n;j++){
				if(q==k){
					ans++;
					for(int k=lef;k<=rig;k++)b[k]=1;
//					cout<<lef<<" "<<rig<<endl;
					break;
				}
				if(b[j]==1||j==n)break;
				q=q^a[j];
				rig++;
			}			
		}

	}
	cout<<ans;
	return 0;
}
