#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005],dis[500005];
void sch(int s,int d){
	ans=max(ans,d);
	for(int i=s;i<=n;i++){
		int x=0;
		for(int j=i;j<=n&&d>=dis[j];j++){
			x^=a[j];
			if(x==k&&dis[j+1]<=d){
				dis[j+1]=d+1;
				sch(j+1,d+1);
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	dis[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dis[i]=-1;
	}
	sch(1,0);
	cout<<ans<<endl;
	return 0;
}