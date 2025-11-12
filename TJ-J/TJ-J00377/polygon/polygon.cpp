#include<iostream>
#include<cmath>
using namespace std;
int a[5001],maxn=-1e9,cnt=0,cnt2=0;
/*void a114514(int n,int l){
	for(int i=l;i<=n;i++)
	if(n>3){
	a114514(n-1,l-1);
	}
}*/
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];//maxn=max(maxn,a[i]);cnt+=a[i];
	}
	/*for(int sl=3;sl<=n;sl++){
	a114514(sl);
	}*/
		for(int l=1;l<=n;l++){
			for(int m=l;m<=n;m++){
				int cnt1=0,maxn1=-1e9;
				for(int i=l;i<=m;i++)
				{
					maxn1=max(maxn1,a[i]);cnt1+=a[i];
				}
				if(cnt1>(maxn*2)){//cout<<maxn1<<" "<<cnt1<<"\n";
				cnt2+=1;
				}
			}
		}
		cout<<cnt2*3;
		return 0;}
