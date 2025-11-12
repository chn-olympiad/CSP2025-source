#include<bits/stdc++.h>
using namespace std;
long long a[1000100];
long long sc[1000100];
long long ans=0;
long long cs=0;
long long z=1;
bool flag=false;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int m;
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>a[i]>>a[i+3]>>a[i+6];
		}
		int max_n=-1e9;
		while(m--){
			for(int i=1;i<=m*3-2;i+=3){
				if(a[i]>max_n){
					max_n=a[i];
				}
			}
			if(max_n!=-1e9){
				ans=ans+max_n;
				if(max_n!=0){
					cs++;
				}else{
					flag=true;
				}
				if(cs>m)break;
				for(int i=1;i<=m*3-2;i+=3){
					if(a[i]==max_n){
						a[i]=-1e9;
						break;
					}
				}
				max_n=-1e9;
			}
			for(int i=2;i<=m*3-1;i+=3){
				if(a[i]>max_n){
					max_n=a[i];
				}
			}
			if(max_n!=-1e9){
				ans=ans+max_n;
				if(max_n!=0){
					cs++;
				}else{
					flag=true;
				}
				if(cs>m)break;
				for(int i=2;i<=m*3-1;i+=3){
					if(a[i]==max_n){
						a[i]=-1e9;
						break;
					}
				}
				max_n=-1e9;
			}
			for(int i=3;i<=m*3;i+=3){
				if(a[i]>max_n){
					max_n=a[i];
				}
			}
			if(max_n!=-1e9){
				ans=ans+max_n;
				if(max_n!=0){
					cs++;
				}else{
					flag=true;
				}
				if(cs>m)break;
				for(int i=3;i<=m*3;i+=3){
					if(a[i]==max_n){
						a[i]=-1e9;
						break;
					}
				}
				max_n=-1e9;
			}
		}
		cs=0;
		if(flag==true){
			sc[z]=ans-1;
		}else{
			sc[z]=ans;
		}
		z++;
		ans=0;
	}
	for(int i=1;i<=z-1;i++){
		cout<<sc[i]<<endl;
	}
	return 0;
}
