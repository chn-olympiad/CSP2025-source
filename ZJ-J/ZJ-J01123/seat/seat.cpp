#include<bits/stdc++.h>
using namespace std ;
int n , m , now , me , s[1043] , z[180][410] ;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m ;
	for(int i=1;i<=n*m;i++)cin >> s[i] ;
	me=s[1] ;
	sort(s+1,s+n*m+1);
	now=n*m ;
	for(int i=1;;){
		for(int j=1;;){
			z[i][j] = s[now--] ;
			if(z[i][j]==me){
				cout << j << " " << i ;
				return 0;
			}
			if(now==n*m)break ;
			if(j%2==1){
				if(i==n){
					j++ ;
    			}
				else{
					i++ ;
				}
			}
			else{
				if(i==1){
					j++ ;
				}
				else{
					i-- ;
				}
			}
			
		}
	}
	return 0;
}
