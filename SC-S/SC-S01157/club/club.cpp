#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int x = 1;x <= t;x++){
		int n,maxn = -1e5+5,sum = 0,a = 0,b = 0,c = 0;
		cin >> n;
		int m[n+5][5];
		for(int i = 0;i < n;i++){
			for(int j = 1;j <= 3;j++){
				cin >> m[i][j];
			}
		}
		for(int i = 0;i < n;i++){
			if(a < (n/2)){
				if(b < (n/2)){
					if(c < (n/2)){
						maxn = max(m[i][1],max(m[i][2],m[i][3]));
						
						if(maxn == m[i][1]){
							a++;
						}else if(maxn == m[i][2]){
							b++;
						}else{
							c++;
						}
					}
				}
			}else if(a == (n/2)){
				if(b == (n/2)){
					maxn = m[i][3];
					c++;
				}else{
					if(m[i][2] > m[i][3]){
						maxn = m[i][2];
						b++;
					}else{
						maxn = m[i][3];
						c++;
					}
				}
				
			}else if(b == (n/2)){
				if(c == (n/2)){
					maxn = m[i][1];
					a++;
				}else{
					if(m[i][1] > m[i][3]){
						maxn = m[i][1];
						a++;
					}else{
						maxn = m[i][3];
						c++;
					}
				}
			
			}else if(c == (n/2)){
				if(a == (n/2)){
					maxn = m[i][2];
					b++;
				}else{
					if(m[i][2] > m[i][1]){
						maxn = m[i][2];
						b++;
					}else{
						maxn = m[i][1];
						a++;
					}
				}
				
			}
			sum += maxn;
			
		}
		cout << sum << endl;
	}
	return 0;
} 