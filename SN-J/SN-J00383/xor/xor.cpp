//SN-J00383 西安高新第二初级中学 初一 张源朔 
#include<bits/stdc++.h>

using namespace std;

long long n,k,a[500005]={},ans=0,jilu=1;
bool pd=0;

struct shu1{
	long long l,r; 
}shu[500005];

bool tmp(shu1 a,shu1 b){
	return a.r<b.r;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}          	
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			int y=a[i];
			for(int x=i+1;x<=j;x++){ 
				y=y^a[x];
			}
			if(y==k){
				shu[jilu].l=i;
				shu[jilu].r=j;
				jilu++;
			}
		}
	} 
	long long now=0;
	int i=1;
	sort(shu+1,shu+jilu,tmp);	
	while(!pd){
		while(shu[i].l<=now){
			i++;
			if(i>=jilu){
				pd=1;
				break;	
			}	
		}
		if(pd){
			break;
		}
		now=shu[i].r; 
		ans++;	
	}
	cout<<ans;
	return 0; 
}
