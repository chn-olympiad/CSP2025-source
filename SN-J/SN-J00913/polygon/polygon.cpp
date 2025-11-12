#include<bits/stdc++.h>
using namespace std;
long long len[5005],qzh[5005],MOD=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len[i];
	}
	sort(len+1,len+n+1);
	if(n<3){
		cout<<0;
		return 0;	
	}
	if(n==3){
		long long sum=len[1]+len[2]+len[3];
		if(sum>2*len[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	else{
		long long sum=0;
		for(int i=1,j=1,k=1;i<=n-2;i++){//有n-2个数需要相加 
			sum+=j;
			sum%MOD;
			k++;
			j+=k;
		}
		cout<<sum;
	}
	return 0;
}

