#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,k,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	int t=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=0) t=1;
	}
	if(!t){
		printf("%d",n/2);
	}else{
		int sum=0,tt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				tt=0;
				sum++;
			}else{//a[i]!=k
				sum+=tt;
				tt=tt^1;
			}
		}
		printf("%d",sum);
	}
	
	return 0;
}
