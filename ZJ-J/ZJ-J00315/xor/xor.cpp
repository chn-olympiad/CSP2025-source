#include<bits/stdc++.h>
using namespace std;
int num[110][500010];
long long a[500010];
int n,k;
void jia(int s){
	long long k=a[s];
	long long t=1,cnt=0;
	while(t<=k){
		t*=2;
		cnt++;
	}
	for(long long i=cnt;i>=0;i--){
		if(k>=pow(2,i)){
			k-=pow(2,i);
			num[i][s]++;
		}
	}
}
long long js(int x,int y){
	long long sum=0;
	for(int i=0;i<=100;i++){
		if((num[i][y]-num[i][x-1])%2!=0)sum+=pow(2,i);
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		jia(i);
	}
	for(int i=0;i<=100;i++){
		for(int j=1;j<=n;j++){
			num[i][j]+=num[i][j-1];
		}
	//	cout<<num[i][n]<<endl;
	}
	int ans=0,e=0;
	for(int i=e+1;i<=n;i++){
		for(int l=1;i+l-1<=n;l++){
			int j=i+l-1;
			if(js(i,j)==k){
			//	cout<<i<<' '<<j<<endl;
				i=j+1;
				ans++;	
			}
		}
		
	}
	cout<<ans;
}
