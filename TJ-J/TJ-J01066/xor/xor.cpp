#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
int a[M],b[M];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	for(int i=0;i<=M;i++){
		a[i]=-1,b[i]=-1;
	}
	int n,k,ans=0;
	cin>>n>>k;
	scanf("%d",&a[1]);
	if(a[1]==k){
		ans++;
		a[1]=-1;
	}
	//cout<<a[1]<<endl;
	for(int i=2;i<=n;i++){
		int temp;
		scanf("%d",&temp);
		if(temp!=k){
			b[1]=temp;
			for(int j=2;j<=i;j++){
				if(a[j-1]==-1){
					//cout<<"-";
					break;
				}
				if((b[1]^a[j-1])==k){
					//cout<<"+";
					ans++;
					break;
				}
				b[j]=(b[1]^a[j-1]);
				//cout<<b[j]<<' ';
			}
		}else{
			ans++;
			//cout<<"++";
		}
		/*for(int j=1;j<=i;j++){
			cout<<b[j]<<' ';
		}
		cout<<endl;*/
		for(int j=1;j<=i;j++){
			a[j]=b[j];
			b[j]=-1;
		}
	}
	cout<<ans;
	return 0;
}
