#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
long long n,m,k,u[N],v[N],w[N],c[12],a[12],sum;
bool cmp(int x,int y){
	return x>y;
}
bool cmp2(int x,int y){
	return x<y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i];
		sum+=w[i];
	}
	sort(w+1,w+1+m,cmp);
	for(int i = 1;i<=k;i++){
		cin >> c[i];
		for(int j = 1;j<=n;j++){
			cin >> a[j];
		}	
		sort(a+1,a+1+n,cmp2);
		long long sum1 = sum;
		for(int j = 1;j<=k;j++){
			if(w[j]>a[j]){
				sum1 = sum1-w[j]+a[j];
			}else{
				break;
			}
		}
		if(sum1+c[i]<sum)	sum = sum1+c[i];
	}
	cout << sum << endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
