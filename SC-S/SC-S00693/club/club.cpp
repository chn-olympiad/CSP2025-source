#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long a1,a2,a33;
long long cnt,sum;
long long b[4];
long long a[205];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		int v=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1>>a2>>a33;
			a[i]=a2;
			if(a1==a33&&a1==0) v++;
			cnt=max(a1,a2);
			cnt=max(cnt,a33);
			sum+=cnt;
			cnt=0;
			//cout<<sum<<endl;
		}
		if(v==n){
		int r=0;
			sort(a+1,a+n+1);
			for(int x=n;x>=n/2+1;x--) r+=a[x];
			cout<<r<<endl;
			r=0;
			v=0;
		}
		else cout<<sum<<endl;
		
		sum=0;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/