#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
	int score;
	bool ME;
}arr[255];
int seats[15][15];
bool cmp(stu a,stu b){
	return a.score>b.score;
}
int C=1,R=1,id=1;
bool up_or_down=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		arr[i].ME=false;
		cin>>arr[i].score;
	}
	arr[1].ME=true;
	sort(arr+1,arr+1+n*m,cmp);
	while(1){
	    if(arr[id].ME)break;
	    if(up_or_down==0)R++;
	    else R--;
	    if(R>n){
	    	C++;
	    	R=n;
	    	up_or_down=1;
		}
		if(R<1){
			C++;
			R=1;
			up_or_down=0;
		}
		id++;
	}
	cout<<C<<" "<<R;
	return 0;
}
