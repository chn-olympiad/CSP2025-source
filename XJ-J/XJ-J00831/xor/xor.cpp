#include"bits/stdc++.h"
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n+1];
    int adv=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int ha=a[i]|a[j];
            for(int h=i+1;h<=j;h++){
                ha=ha|a[h];
            }
            if(ha==k){
            	adv=adv+1;
                i=j+1;
            }
        }if(a[i]==k){
        	adv=adv+1;
		}
    }
    cout<<adv;
}
