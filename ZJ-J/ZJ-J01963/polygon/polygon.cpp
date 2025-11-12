//#Shang4Shan3Ruo6Shui4
//4
#include<bits/stdc++.h>
using namespace std;
int q=998244353;
int qiuhe(int a,int b){
	long long sum1=1;
	for(int i=b;i>b-a;i--)sum1=(sum1*i)%q;
	for(int i=1;i<=a;i++)sum1=sum1/i;
	return sum1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	//24point get
	if(a[n-1]==1){
		for(int i=3;i<=n;i++){
			sum=(sum+qiuhe(i,n))%q;
		}
		cout<<sum%q;
		return 0;
	}
	//40point get
	for(int i=3;i<=n;i++){
		for(int j=0;j<pow(2,i-1);j++){
			long long sum1=0,k=j,wei=1;
			while(k){
				if(k%2==1)sum1+=a[wei];
				wei++;
				k>>=1;
			}
			if(sum1>a[i])sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
