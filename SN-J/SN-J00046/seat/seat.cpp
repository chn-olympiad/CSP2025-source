//SN-J00046 余兆淳 渭南实验初级中学
#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r,n[100],x=1,p,e,q,s,u;
	cin >> c >> r >> n[100];
	for(int u=2;u<=c*r;u++){
		if(n[u]>n[1]){
			x++;
		}
	}
	for(int j=1;j<=r;j++){
		for(int i =1;i<=c;i++){
			s=x-x%c;
			if(s%2==0 && x%c==0){
				e=1;
				q=x/r;
			}
			else if(s%2==0){
				e=x%c+1;
				q=s%c+1;
			} 
			else{
				e=c-x%c;
				q=s%c+1;
			} 
		}
	}
	cout << q << " " << e;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
