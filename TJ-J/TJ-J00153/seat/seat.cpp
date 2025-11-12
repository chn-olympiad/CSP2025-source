#include<bits/stdc++.h>
using namespace std;
long long a[1111111]={0},c[1111][1111]={0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n=0,m=0;
	cin>>n>>m;
	long long t=n*m,q=t;
	for(long long i=1;i<=t;i++){
        cin>>a[i];
	}
	if(n==1 && m==1){
        cout<<1<<' '<<1;
        return 0;
	}
	long long r=a[1];
	sort(a+1,a+t+1);
	for(long long i=1;i<=m;i++){
        for(long long j=1;j<=n;j++){
            c[i][j]=a[q--];
        }
        if(i==m){
            break;
        }
        i++;
        for(long long j=n;j>=1;j--){
            c[i][j]=a[q--];
        }
	}
	for(long long i=1;i<=m;i++){
        for(long long j=1;j<=n;j++){
            if(c[i][j]==r){
                cout<<i<<' '<<j;
                return 0;
            }
        }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
