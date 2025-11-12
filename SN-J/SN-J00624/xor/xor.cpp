#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,b[N],sum,dis[N],k;
int ch(int a){
	int ans=0,cnt=0,x=0;
	memset(dis,0,sizeof(dis));
	while(a){
		int k=a%2;
		cnt++;
		dis[cnt]=k;
		a/=2;
	};
	for(int i=1;i<=cnt;i++){
		ans+=dis[i]*pow(10,x);
		x++;
	}
	return ans;
} 
int yor(int a,int b){
	int x=ch(a),y=ch(b),ans=0,cnt=0;
	while(x||y){
		if((x%10)!=(y%10)){
			ans+=pow(2,cnt);
		}
		cnt++;
		x/=10;
		y/=10;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++){
		int bns=b[i];
		if(bns==k){
			sum++;
		}else{
			for(int j=i+1;j<=n;j++){
				bns=yor(bns,b[j]);
				if(bns==k){
					sum++;
					break;
				}
			}
		}
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
}
