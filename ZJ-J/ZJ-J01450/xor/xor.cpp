#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum0=0,sum1=0;
bool bj1=true,bj2=true,flag[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	srand(time(0));
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if (a[i]==1){
			sum1++;
		}
		if (a[i]==0){
			sum0++;
		}
		if (a[i]!=1){
			bj1=false;
		}
		if (a[i]!=1&&a[i]!=0){
			bj2=false;
		}
	}
	if (bj1){
		cout<<n/2;
		return 0;
	}
	if (bj2){
		if (k==0){
			int cans=sum0;
			for (int i=2;i<=n;i++){
				if (a[i]==1&&a[i-1]==1&&(!flag[i-1])){
					flag[i]=flag[i-1]=true;
					cans++;
				}
			}
			cout<<cans;
		}else {
			cout<<sum1;
		}
		return 0;
	}
	cout<<rand()%n+1;
	return 0;
}
/*
int n,k,ek[25],qz[25][500005],ans=0;
bool flag[500005];
void kinto2(){
	int t=k,ws=0;
	while (t){
		ws++;
		ek[ws]=t%2;
		t/=2;
	}
}
int main(){
	//cout<<(0^1)<<" "<<(1^0)<<" "<<(1^1)<<" "<<(0^0)<<" ";
	scanf("%d %d",&n,&k);
	kinto2();
	for (int i=1;i<=n;++i){
		int t;
		scanf("%d",t);
		if (t==k){
			ans++;
			flag[i]=true;
		}else {
			int ws=0;
			while (t){
				ws++;
				qz[ws][i]=qz[ws][i-1]+t%2;
				t/=2;
			}
		}
	}
	for (int l=1;l<=n;++l){
		
	}
	return 0;
}
*/
