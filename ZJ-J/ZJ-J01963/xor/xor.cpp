//#Shang4Shan3Ruo6Shui4
//3
#include<bits/stdc++.h>
using namespace std;
struct abc{
	int l,r;
};
abc b[500005];
int cmp(abc x,abc y){
	return (x.r-x.l)<(y.r-y.l);
}
bool c[500005]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005],sum=0,f0=1,f1=1,cc=0,sums=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f0=0;
		if(a[i]!=0&&a[i]!=1)f1=0;
	}
	if(f0){
		cout<<n/2;
		return 0;
	}
	if(f1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k)sum++;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int num=a[i];
		if(num==k){
			b[sum].l=i;
			b[sum].r=i;
			sum++;
		}
		for(int j=i+1;j<=n;j++){
			int num1=num^a[j];
			if(num1==k){
				b[sum].l=i;
				b[sum].r=j;
				sum++;
			}
			num=num1;
		}
	}
	sort(b+1,b+1+n,cmp);
	int chang=0,ff=1;
	while(cc<sum){
		if((b[cc].r-b[cc].l+1)!=chang){
			chang=b[cc].r-b[cc].l+1;
			if(ff==0){
				cout<<sums;
				return 0;
			}
			ff=0;
		}
			int fx=1;
			for(int i=b[cc].l;i<=b[cc].r;i++){
				if(c[i]==1){
					fx=0;
					break;
				}
			}
			if(fx){
				for(int i=b[cc].l;i<=b[cc].r;i++)c[i]=1;
				ff=1;
				sums++;
			}
		cc++;
	}
	cout<<sums;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
