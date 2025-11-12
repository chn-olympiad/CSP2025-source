#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],m;
set<string> se;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		sort(a,a+n);
		if(a[0]+a[1]+a[2]>2*a[2]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else if(n>=3&&n<=5){
		sort(a,a+n);
		for(int i=0;i<n-2;i++){
			for(int j=i+1;i<n-1;j++){
				for(int k=j+1;k<n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]){
						m++;
					}
				}
			}
		}
		for(int i=0;i<n-3;i++){
			for(int j=i+1;i<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int g=k+1;g<n;g++){
					    if(a[i]+a[j]+a[k]+a[g]>2*a[g]){
					    	m++;
					    }
					}
				}
			}
		}
		for(int i=0;i<n-4;i++){
			for(int j=i+1;i<n-3;j++){
				for(int k=j+1;k<n-2;k++){
					for(int g=k+1;g<n-1;g++){
					    for(int w=g+1;w<n;w++){
					    	if(a[i]+a[j]+a[k]+a[g]+a[w]>2*a[w]){
					    	    m++;
					        }
						}
					}
				}
			}
		}
	}
	else{
		cout<<"buhuile-_-||";
		return 0;
	}
	return 0;
}
