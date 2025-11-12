#include<bits/stdc++.h>
using namespace std;
int a[1000000],qzh[1000000],biaoji[1000000],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,e;
	cin>>n>>e;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qzh[i]=qzh[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int lo=i+j-1,flag=0;
			for(int p=j;p<=lo;p++)if(biaoji[p]==1)flag=1;
			if(flag)continue;
			//cout<<j<<" "<<lo<<" ";cout<<(qzh[lo]^qzh[j-1])<<'\n';
            if((qzh[lo]^qzh[j-1])==e){
            	ans++;
				for(int k=j;k<=lo;k++)biaoji[k]=1;
            }
		}
	}
	cout<<ans;
}