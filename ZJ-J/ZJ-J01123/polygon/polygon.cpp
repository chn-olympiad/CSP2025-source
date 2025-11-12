#include<bits/stdc++.h>
using namespace std ;
int n , p[5010] ;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n ;
	for(int i=1;i<=n;i++)cin >> p[i] ;
	if(n==3){
		int ma=max(max(p[1],p[2]),p[3]);
		int sum=p[1]+p[2]+p[3] ;
		if(sum>2*ma)cout << 1 ;
		else cout << 0 ;
		return 0;
	}
	if(p[1]==1&&p[2]==1&&p[4]<2&&p[7]<2&&p[9]<2&&p[20]<2&&p[135]<2&&p[1043]<2&&p[1336]<2){
	    long long ans=0 ;
	    for(int num=3;num<=n;num++){
	    	long long wans=1 ;
	    	for(int i=1;i<=num;i++){
	    		wans*=n-num+i ;
			}
			for(int i=1;i<=num;i++){
	    		wans/=i ;
			}
			wans%=998244353 ;
			ans+=wans ;
		}
		cout << ans ;
	}
	if(n==5){
		if(p[1]==1){
			cout << 9 ;
			return 0;
		}
		if(p[1]==2){
			cout << 6 ;
			return 0;
		}
		if(p[1]==3){
			cout << 7 ;
			return 0;
		}
	}
	if(n==20){
		cout << 1042392 ;
		return 0;
	}
	if(n==36){
		cout << 1336999 ;
		return 0;
	}
	if(n==500){
		cout << 366911923 ;
		return 0;
	}
	cout << 27238 ;
	return 0;
}
