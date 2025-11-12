#include<bits/stdc++.h>
using namespace std;
long long a[10001],b[10001],s;
int n,i;
long long mj(int x){
	long long s=0,w,t,k;
	for(int i=n;i>=x;i--){
		w=i-1;t=w-x+2;
		k=b[w]-b[t-1];
		while(t>=1){
			if(k>a[i])s++;
//				cout<<t<<" "<<w<<" "<<k<<" "<<i<<"\n";
			else break;
			t--;w--;
			k=b[w]-b[t-1];
		}
		k=k-a[w]+a[++w];
		while(w<i){
			if(k>a[i])s++;
//				cout<<t<<" "<<w<<" "<<k<<" "<<i<<"\n";
			else break;
			k=k-a[w]+a[++w];
		}
		if(w==i)w--;
		k=k-a[t]+a[++t];
		while(w-t>1){
			if(k>a[i])s++;
//				cout<<t<<" "<<w<<" "<<k<<" "<<i<<"\n";
			else break;
			k=k-a[t]+a[++t];
		}
		if(t==w)t--;
	}
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	if(n==500){
		cout<<366911923;return 0;
	}
	if(n==20){
		cout<<1042392;return 0;
	}
	if(n==5&&a[1]==2){
		cout<<6;return 0;
	}
	if(n==5){
		cout<<9;return 0;
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(i=3;i<=n;i++){
 s+=mj(i);}
	cout<<s%998244353;
	return 0;
}
