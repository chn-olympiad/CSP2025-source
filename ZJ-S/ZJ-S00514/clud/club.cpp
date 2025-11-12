#include<bits/stdc++.h>
using namespace std;
long long t;
long long n;
long long a[10010],b[10010],c[10010];
long long maxn=-1,num;
long long al,bl,cl; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		al=0;
		bl=0;
		cl=0;
		num=0;
		maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]>b[i]&&a[i]>c[i]&&2*al<=n){
				al++;
				num+=a[i];
			}else if(b[i]>a[i]&&b[i]>c[i]&&2*bl<=n){
				bl++;
				num+=b[i];
			}else{
				if(c[i]>a[i]&&c[i]>b[i]&&2*cl<=n){
					cl++;
					num+=c[i];
				}	
			}
		}
		if(num>maxn){
			maxn=num;
		}
		cout<<maxn<<endl;
	}
	return 0;
}