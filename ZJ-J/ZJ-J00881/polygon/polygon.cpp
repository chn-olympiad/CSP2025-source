#include<bits/stdc++.h>
using namespace std;
int n,a[114514],cnt;
int su(int p){
	int h=0;
	while(p){
		h+=p;
		p--;
	}
	return h;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n<=3){
		if(n<=2){
			cout<<0;
			return 0;
		}else{
			if(a[1]+a[0]>a[2]){
				cout<<1;
				return 0;
			}else{
				cout<<0;
				return 0;
			}
		}
	}
	if(a[n-1]==1){
		cout<<0;
		return 0;
	}
	for(int i=2;i<n;i++){
		for(int j=i-1;j>=0;j--){
			int h=a[j];
			for(int k=j-1;k>=0;k--){
				h+=a[k];
				if(h>a[i]){
					cnt+=(1+su(k));
					h-=a[k];
					continue;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
