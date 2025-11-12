#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],l,x,h;
bool c[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		c[i]=1;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			h++,c[i]=0;
		}
	}
	for(int i=0;i<n;i++){
		if(c[i]){
			int j=i+1,d=a[i];
			bool f=0;
			while(j<n&&c[j]){
				d^=a[j];
				if(d==k){
					f=1;
					break;
				}
				j++;
			}
			if(f){
				h++;
				for(int o=i;o<j;o++){
					c[i]=0;
				}
			}
		}
	} 
	cout<<h;
	return 0;
}
