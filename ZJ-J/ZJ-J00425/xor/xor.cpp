#include<bits/stdc++.h>
using namespace std;
const int le=5e5+10;
struct lr{
	int l,r;
}z[le],y[le];
int n,k,len=0;
int a[le],sum[le]/*“ÏªÚ*/,l[le],dp[le];
map<int,int> mp;
bool cmp(lr a,lr b){
	return a.l<b.l;
}
/*int calc(int x){
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(dp[mid]==0){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	return l;
}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1] xor a[i];
	}
	mp[0]=0;
	for(int i=1;i<=n;i++){
		int fi=k xor sum[i];
		if(mp.find(fi)!=mp.end()){
			l[i]=mp[fi];
			z[++len].l=l[i]+1,z[len].r=i;//
			y[len].l=l[i]+1,y[len].r=i;//
		}
		mp[sum[i]]=i;
	}
	/*for(int i=1;i<=len;i++){
		cout<<z[i].l<<" "<<z[i].r<<endl;
	}*/
	//memset(dp,0,sizeof(dp));
	sort(y+1,y+len+1,cmp);
	/*for(int i=1;i<=len;i++){
		int pos=calc();
		if(dp[pos]<z[i].l){
			dp[pos+1]=z[i].r;
		}
	}*/
	int pos=0;
	for(int i=1;i<=len;i++){
		if(dp[pos]<z[i].l){
			dp[++pos]=z[i].r;
		}
	}
	cout<<pos;
	return 0;
} 
