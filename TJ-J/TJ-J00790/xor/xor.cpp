#include<bits/stdc++.h> 
using namespace std;
int n,k,a[100005],max=-999,num=0,p=0;
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    for(int i=1;i<=n;i++){
    	for(int j=i;j<=n;j++){
    		p++;
    		num+=a[j];
    		if(num==k){
    		    if(max<p){
    		    	max=p;
				}
			}
		}
	}
	cout<<p;
}
