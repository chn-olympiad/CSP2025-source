#include<bits/stdc++.h>
using namespace std;
int n,m[5005],sum;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>m[i];
	}
	for(int i=1;i<=n;i++){
        if(m[i]+m[i+1]>m[i+2]||m[i]+m[i+2]==m[i+3]){
        	sum++;
		}
	}

    for(int i=1;i<=n;i++){
    	if(m[i]==m[i+1]){
			sum+=n-2;
			break;
		}
		else{
            sum+=n;
            break;
		}
	}
	cout<<sum+1;
	return 0;
}