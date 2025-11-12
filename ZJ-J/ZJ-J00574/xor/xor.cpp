#include<bits/stdc++.h>
using namespace std;
struct sub{
	int l,r;
};
bool cmp(sub x,sub y){
	if(x.r!=y.r) return x.r<y.r;
	else return x.l>y.l;
}
bool k_2[25],a_2[500005][25],b_2[500005][25],c_2[500005][25];
int a[500005],c[500005],t=0,b[500005];
sub q[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	    //转二 
	//a 
	for(int i=1;i<=n;i++){
		int x=a[i];
		int z=0;
		while(x){
			z++;
			a_2[i][z]=x%2;
			x/=2;
		}
	}
	//k
	int k1=k,zz=0;
	while(k1){
		zz++;
		k_2[zz]=k1%2;
		k1/=2;
	}
	
	//a前缀和->b
	for(int i=1;i<=n;i++){
		for(int j=1;j<=21;j++){
			if(a_2[i][j]!=b_2[i-1][j]) b_2[i][j]=true;	
			else b_2[i][j]=false;
		}
	}
	
	//c= b xor k
	for(int i=1;i<=n;i++){
		for(int j=1;j<=21;j++){
			if(b_2[i][j]!=k_2[j]) c_2[i][j]=true;
			else c_2[i][j]=false;
		}
	}
	
	//b,c 转10 
	for(int i=1;i<=n;i++){
		for(int j=21;j>=1;j--) c[i]*=2,c[i]+=c_2[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=21;j>=1;j--) b[i]*=2,b[i]+=b_2[i][j];
	}
	
	//寻找区间 
	c[0]=k;
	for(int i=0;i<n;i++){
		for(int j=1+i;j<=n;j++)
		if(c[i]==b[j]){
			t++;
			q[t].l=i+1;
			q[t].r=j;
		}
	}
	
	//贪心 
	sort(q+1,q+t+1,cmp);
	if(t) ans++;
	for(int i=2;i<=t;i++){
		if(q[i].l>q[i-1].r){
			ans++;
		} 
		while(q[i+1].r==q[i].r) i++;
	}
	
	cout<<ans;
	return 0;
}
/*
4 0
2 1 0 3
*/


