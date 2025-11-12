#include<bits/stdc++.h>
using namespace std;
long long n;
long long sum;
vector<long long> a(1,0);
vector<long long> b(1,0);
int main(){
	cin>>n;
	for(long long i=1,a1;i<=n;i++){
		cin>>a1;
		a.push_back(a1);
	}sort(a.begin(),a.end());
	for(long long i=1,x=0;i<=n;i++){
		x+=a[i];
		b.push_back(x);
	}for(long long i=3;i<=n;i++){
		if(b[i]<=a[i]*2) continue;
		else sum++;
		for(long long j=1;j<i;j++){
			if(b[i]-a[j]<=a[i]*2 || i-1<3) break;
			else sum++;
			long long x1=a[j]+a[j+1],x2=2;
			while(i-x2>=3 && b[i]-x1>a[i]*2){
				sum++,x1+=a[j+x2],x2++;
			}
		}
	}cout<<sum%998244353;
	return 0;
}
