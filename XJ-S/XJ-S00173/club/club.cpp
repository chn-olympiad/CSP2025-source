#include <bits/stdc++.h>
using namespace std;
long long int t;
long long int a[9999];
int cnt[9999]; 
int club[4][4];
int pd;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t; 
	for(int k=1;k<=t;k++){
		int n;
		cin>>n;
		int maxn=0;
		for(int i=1;i<=n;i++){
			a[1]=0,a[2]=0,a[3]=0;
			cin>>a[1]>>a[2]>>a[3];
			for(int i=1;i<=n;i++){
				for(int j=0;j<=i;j++){
					if(a[i+1]>a[j+1]) {
						swap(a[i+1],a[j+1]);
					}
				}
			} 
			maxn=a[1]+maxn; 			
		}
		cout<<maxn<<endl;
	}
	
	return 0;
}
