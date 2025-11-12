#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n = 1;
	int m = 1;
	int s1,s2,s3,s4;	
	cin >> n >> m >> s1 >> s2 >> s3 >> s4;
	for(int i= 1;i<=1;i++){
		if(s1 > s2){
			cout << n << " " << m+1;
		}else if(s2 > s3){
			cout << n+1 << " " << m+2;
		}else if(s3 > s4){
			cout << n+2 << " " << m;
		}else {
			cout << n+2 << " " << m;
		}
	}
	return 0;
} 
