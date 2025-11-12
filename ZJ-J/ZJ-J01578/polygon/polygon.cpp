#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0<<endl;
		return 0;
	}else if(n==3){
		if(a[1]+a[2]<=a[3]){
			cout<<0;
			return 0;
		} 
		cout<<1;
		return 0;
	}
	int s1=0;
	for(int i=1;i<=n;i++){
		int mx=-1,s=0;
		for(int j=1;j<=n;j++){
			s+=a[j];
			mx=max(mx,a[j]);
			if(s>mx*2){
				s1++;
				s=0,mx=-1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int k=2;k<n-i;k++){
			int mx=-1,s=a[i];
			for(int l=i+k;l<=n;l++){
				for(int j=l;j<=l+k;j++){
					s+=a[j];
					mx=max(mx,a[j]);
					if(s>mx*2){
						s1++;
						s=0,mx=-1;
					}
				}
			}
			
		}
	}
	cout<<s1;
	
	return 0;
}