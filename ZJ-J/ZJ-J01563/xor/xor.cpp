#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int n,k,ans=0,a[N],sum[N];
struct node{
	int l,r;
}sit[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
//	for(int i=1;i<=n;i++)
//		cout<<sum[i]<<" ";
//	cout<<endl;
	int l,r,cnt=0;
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((sum[i]^sum[j])==k){
				cnt++;
				sit[cnt].l=i+1,sit[cnt].r=j;
			//	cout<<i+1<<" "<<j<<endl;
				if(sit[cnt].r<sit[cnt-1].r){
					sit[cnt-1].l=sit[cnt].l;
					sit[cnt-1].r=sit[cnt].r;
					sit[cnt].l=0;
					sit[cnt].r=0;
					cnt--;
				}
				if(sit[cnt].r==sit[cnt-1].r){
					sit[cnt].l=0;
					sit[cnt].r=0;
					cnt--;	
				}
				if(sit[cnt].r>sit[cnt-1].r&&sit[cnt].l<=sit[cnt-1].r){
					sit[cnt].l=0;
					sit[cnt].r=0;
					cnt--;	
				}			
//				if(sit[cnt].l>=sit[cnt-1].r) good!!!!!!!!				
			}
		}
	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<sit[i].l<<" "<<sit[i].r<<endl;;
//	}
	cout<<cnt;
	return 0;
}
