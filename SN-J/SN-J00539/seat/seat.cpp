#include <bits/stdc++.h>

using namespace std;
int m,n;
int stu[101];
int r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> m >> n;
	int ji=m*n;
	for(int i=1;i<=ji;i++){
		cin >> stu[i];
		if(i==1){
			r=stu[i];
		}
	}
	sort(stu+1,stu+1+ji);
	int wei;
	for(int i=1;i<=ji;i++){
		if(stu[i]==r){
			wei=i;
			break;
		}
	}
	wei--;
	int x=1,y=1;
	while(wei--){
		if(y%2==1){
			if(x<n){
				x++;
			}
			else{
				y++;
			}
		}
		else{
			if(x>1){
				x--;
			}
			else{
				y++;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
