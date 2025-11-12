#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T,n;
int a[100010][4],b[100010],sm=0,pd[4];
int dfs(int k){
	if (k>n){
		return sm;
	}
	int n1=0;
	for (int i=1;i<=3;i++){
		if (pd[i]<n/2){
			sm+=a[k][i];
			pd[i]++;
			n1=max(n1,dfs(k+1));
			sm-=a[k][i];
			pd[i]--;
		}
	}
	return n1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--){
		sm=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if (n>=1&&n<=10) cout<<dfs(1)<<endl;
		if (n==100000){
			for (int i=1;i<=n;i++)
				b[i]=a[i][1];
			sort(b+1,b+n+1);
			int mx=0;
			for (int i=50001;i<=100000;i++){
				mx+=b[i];
			}
			cout<<mx<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}