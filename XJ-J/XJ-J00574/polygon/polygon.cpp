#include<bits/stdc++.h>
using namespace std;
int n,num[10010],ans=0;
bool pd(int a,int b){
	int nx=b-a+1;
	int sum=0,max=0;
	for(int i=a;i<=b;i++){
		sum+=num[i];
		if(max<num[i]) max=num[i];
	}
	if(sum>max*2) return true;
	else return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> num[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(pd(i,j)){
				ans++;
			}
		}
	}
	cout << ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
