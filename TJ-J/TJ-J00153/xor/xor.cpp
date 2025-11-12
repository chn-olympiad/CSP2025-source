#include<bits/stdc++.h>
using namespace std;
long long a[111111]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n=0,k=0;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
        cin>>a[i];
	}
	long long m=-12345;
	for(long long k=1;k<=n;k++){
        long long c=0;
        for(long long i=1;i<=n;i++){
            long long p=0;
            for(long long j=1;j<=i;j++){
                p=p|a[i];
            }
            if(p==k){
                c++;
            }
        }
        if(c>m){
            m=c;
        }
	}
    cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
