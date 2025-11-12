#include <bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,x,y,a[5005],b[5005],c[5005];
long long s;
bool f=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	sort(a+1,a+1+n);
	c[0]=0;
	for(int i=1;i<=n;i++) c[i]=c[i-1]+a[i];
	for(int i=n;i>=3;i--){
		x=c[i]-a[i]*2;
		if(x<=0) continue;
		for(int j=1;j<i;j++){
			if(a[j]>x) break;
			if(j==1) s++;
			else{
				s++;
				if(!f) break;
				if(c[j]<x) s+=((int)pow(2,j)/2)-1;
				else{
					f=false;
					s+=((int)pow(2,j)/2)-2;
				}
			}
		}
	}
	cout<<s%M<<endl;
	return 0;
}
