#include<iostream>
#include<algorithm>
using namespace std;
int a[100010],n,sum,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
		cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int k=1;k<=n;k++){
		for(int j=2;j<=n;j++){
			for(int i=k;i<=k+j;i++){
				sum+=a[i];
			}
			if(sum>=a[j+k]*2){
				ans++;
			}
		}			
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}


