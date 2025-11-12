#include<bits/stdc++.h>
using namespace std;
int n,m,cz[105],r,rpm=1;//n表示行数，m表示列数 ,r=小R的成绩 ,rpm表示小R的名次 
int rn,rm;//rn表示小r的座位行数，rm表示小r的座位列数 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cz[i];
	}
	for(int i=2;i<=n*m;i++){
		if (cz[1]<cz[i]){
			rpm++;
		}
	}

	//现在我已经求出R的名次，已知有n行，m列，且从高到低蛇形排序，求R的座位号（rm rn）：
	rm= (rpm-1)/n+1;
	if (rm%2==0) rn=n-rpm%n+1;
	else {
		rn=rpm%n;
		if (rn==0) rn=n;
	}
	cout<<rm<<" "<<rn;
	
	
	
	
	
	return 0;
} 
