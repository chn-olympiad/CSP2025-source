#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[101][101];
int s[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&s[i]);
	x=s[1];
	for(int i=1;i<=n*m;i++)
		for(int j=i;j>1;j--)
			if(s[j]>s[j-1])
				swap(s[j],s[j-1]);
	int sum=0;
	for(int i=1;i<=n/2;){
		for(int j=1;j<=m;j++){
			sum++;
			if(s[sum]==x){
				printf("%d %d",i,j);
				return 0;
			}
		}
		i++;
		for(int j=m;j>=1;j--){
			sum++;
			if(s[sum]==x){
				printf("%d %d",i,j);
				return 0;
			}
		}
		i++;
	}
	if(n%2!=0){
		for(int i=n;i==n;)
			for(int j=1;j<=m;j++){
				sum++;
				if(s[sum]==x){
					printf("%d %d",i,j);
					return 0;
				}
			}
	}
	return 0;
}
