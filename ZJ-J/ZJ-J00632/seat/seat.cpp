#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	int xiao;
	cin>>xiao;
	int temp,s=1;
	for(int i=2;i<=num;i++){
		cin>>temp;
		if(temp>xiao){
			s++;
		}
	}
	int l=int(s*1.00/n+0.99999);
	int t=s-(n*(l-1));
	int h;
	if(l%2==0){
		h=n-t+1;
	}else{
		h=t;
	}
	cout<<l<<" "<<h<<"\n";
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
