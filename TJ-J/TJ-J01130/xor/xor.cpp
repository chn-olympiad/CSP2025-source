#include<bits/stdc++.h>
using namespace std;
int n,m,a[500000],book[500000]={},p=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}for(int i=1;i<=n;i++){
		int o=0,s=0,l=0;
		for(int j=n-i+1;j>=1;j--){s=0;o=0;
			for(int k=0;k<i;k++){
				if(book[k+j]==1){
					o=1;l=k;break;
				}s^=a[k+j];
			}if(o){j-=i-l-1;continue;
			}
			if(s==m){
				for(int k=0;k<i;k++){
					book[k+j]=1;
				}p++;
			}
		}
	}cout<<p;
    return 0;
}/*4 2
2 1 0 3*/

