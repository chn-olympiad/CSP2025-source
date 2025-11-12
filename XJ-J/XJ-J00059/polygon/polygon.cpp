#include<bits/stdc++.h>
using namespace std;
int n;
int s;
int ma;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.our","w",stdout);	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int m=i+1;m<=n;m++){
				s+=1;
				
			}
		}
	}	
	printf("%d",s);
	return 0;	
}
