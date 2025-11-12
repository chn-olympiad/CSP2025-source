#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long num[N],cnt,k,n,pre[N],len;//
bool bao[N];
long long sum(long long x,long long y){
	for(long long i=x;i<=y;i++){
		if(bao[i]) return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>num[1];
	pre[1]=num[1];
	for(long long i=2;i<=n;i++){
		cin>>num[i];
		pre[i]=(pre[i-1]^num[i]);
	}
	for(long long i=1;i<=n;i++){
		if(num[i]==k) {
			cnt++;

			bao[i]=1;
		}
	}
	len=2;
	long long tmp=n;
	while(tmp-- and len<=n){
		for(long long i=1;i<=n-len+1; ){
			if((pre[i+len-1]^pre[i-1])==k and sum(i,i+len-1)){
				cnt++;
				for(long long  j=i;j<=i+len-1;j++){
					bao[j]=1;
				}
				i+=len;
			}
			else i++;
		}
		len++;
	}
	cout<<cnt;
	return 0;
}
//what a cold thing?! my answer of example 5 is one smaller than the real answer 
/*TAT
  | |
  | |
  | |
  | |
  | |
  | |
  | |
  | |
  | |
  | |*/
                                                                                
