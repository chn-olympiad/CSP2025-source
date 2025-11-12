#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s_num,uppers=0,v0;
	cin>>n>>m;
	cin>>s_num;
	for(int i=0;i<n*m-1;i++){
		cin>>v0;
		if(v0>s_num){
			uppers++;
		}
	}
	if((uppers)/n%2==0){ // 单数列 
		cout<<uppers/n+1<<" "<<uppers%n+1;
	}else{				 // 双数列 
		cout<<uppers/n+1<<" "<<n-uppers%n; 
	}
	
	return 0;
}

/*

n=5,m=4:

  | 01  02  03  04
  | --------------
1 | 01  10  11  20
  |
2 | 02  09  12  19
  |
3 | 03  08  13  18
  |
4 | 04  07  14  17
  |
5 | 05  06  15  16
 

*/

