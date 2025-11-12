#include<bits/stdc++.h>
using namespace std;
int stu[225],lis[15][15],n,m,l,num=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>stu[i];
	}l=stu[1];sort(stu+1,stu+n*m+1,greater<int>());	
	for(int i=1;i<=n;i++){
	    if(i%2==1){
	    	for(int j=1;j<=m;j++){
	    		if(stu[num]==l){
	    			cout<<i<<" "<<j;
	    			return 0;
				}num++;
			}	
		}else{
			for(int j=m;j>0;j--){
	    		if(stu[num]==l){
	    			cout<<i<<" "<<j;
	    			return 0;
				}num++;
			}	
		}
	}
    return 0;
}
