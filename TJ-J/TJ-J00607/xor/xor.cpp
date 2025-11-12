#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=5e7+10;
long long a[N]={0},p[N]={0};
struct node{
	long long l;
	long long r;
}can[M];
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,cnt=0,ans=0;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]^a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
//			p[i][j]=p[i][j-1]^a[j];
//			cout<<(p[j]^p[i-1])<<'\n';
//			cout<<i<<" "<<j<<'\n';
			if((p[j]^p[i-1])==k){
				can[++cnt]=(node){i,j};
//				if(cnt>=50000000){
//					cout<<cnt;
//				}
//				cout<<can[cnt].l<<" "<<can[cnt].r<<'\n';
//				cout<<cnt<<'\n';
			}
		}
	}
//	cout<<cnt<<'\n';
	sort(can+1,can+1+cnt,cmp);
	long long tmp=0;
	for(long long i=1;i<=cnt;i++){
//		cout<<can[i].l<<" "<<can[i].r<<'\n';
		if(can[i].l>tmp){
			ans++;
			tmp=can[i].r;
		}
	}
	cout<<ans;
	return 0;
}
