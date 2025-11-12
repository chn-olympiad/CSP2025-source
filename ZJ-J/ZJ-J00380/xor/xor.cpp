#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[500005],r,sum,tot;
bool flag=false;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>=2)flag=true;
	}
	if(!flag){
		if(m==1){
			for(int i=1;i<=n;i++){
				if(a[i])sum++;
			}
			printf("%d",sum);
		}
		else{
			for(int i=1;i<=n;i++){
				if(!a[i])sum++,tot=0;
				else{
					tot++;
					if(tot%2==0)sum++;
				}
			}
			printf("%d",sum);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		sum=a[i];
		if(sum==m)f[i]++,r=i;
		else{
			for(int j=i-1;j>=r+1;j--){
				sum=sum^a[j];
				if(sum==m){
					f[i]++;
					r=i;
					break;
				}
			}
		}
	}
	printf("%d",f[n]);
	return 0;
}
