#include<iostream>
using namespace std;

int n,k,zong=0;
int a[500005]={};
bool b[500005]={};

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int l=1;l<=n-i;l++){
			int sum=0;
			for(int j=l;j<=l+i;j++){
				if(b[j]){
					sum=-1;
					break;
				}else{
					sum=sum^a[j];
				}
			}
			if(sum==k){
				zong++;
				for(int j=l;j<=l+i;j++){
					b[j]=true;
				}
			}
		}
	}
	printf("%d",zong);
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}
