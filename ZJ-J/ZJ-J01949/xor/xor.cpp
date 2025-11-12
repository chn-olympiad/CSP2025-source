#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],now[500005];
bool judge(int i,int j,int n){
	for(int k=i+1;k<=j;k++){
		if(now[k]==1){
			return 0;
		}
	}
	for(int k=i+1;k<=j;k++){
		now[k]=1;
	}
//	for(int i=0;i<=n;i++){
//		cout<<now[i];
//	}cout<<endl;
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
		//cout<<b[i]<<" ";
	}
	//cout<<endl;
	int cnt=0;
	for(int i=0;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			if((b[i]^b[j])==k){
				//cout<<j<<" "<<i<<" "<<(b[i]^b[j])<<";"<<endl;
				if(judge(j,i,n)){
					cnt++;
				}
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
