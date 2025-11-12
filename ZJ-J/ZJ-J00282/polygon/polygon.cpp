#include<bits/stdc++.h>
using namespace std;
int a[5001];
struct F{
	int data;
	long long max=0;
	long long fun=0;
}f[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a[i]);
	}
	sort(a,a+n);
	int j,k;
	for(int i=2;i<n;i++){
		j=i-1;
		k=i-2;
		while(j>=0&&k>=0&&k<j){
			while(a[j]+a[k]>a[i]){
				k--;
			}
			f[i].fun+=f[j].fun+f[k].fun+1;
			
			j--;
		}
		
	}
	printf("%d",f[n-1].fun);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
