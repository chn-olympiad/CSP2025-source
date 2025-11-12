#include<bits/stdc++.h>
using namespace std;
int a[5009];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		long long num=0;
		int maxn=0;
		for(int j=i;j<=n;j++){
			if(a[j]>maxn){
				maxn=a[j];
			}
			num+=a[j];
			if(num>2*maxn&&j>=i+2){
				sum++;
				
				sum%=998244353;
				int kk=0,mk=0;
				for(int k=j-1;k>=i;k--){
					kk+=a[k];
					if(kk>2*maxn){
						mk=k;
						break;
					}
				}
				int temp=mk-i+1;
				int jfj=0;
				for(int k=1;k<temp;k++){
					jfj+=k;
				}
				sum+=jfj;
				sum%=998244353;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
