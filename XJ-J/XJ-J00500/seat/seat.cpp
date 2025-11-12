#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("srat.out","w",stdout);
	int m,n,w,num[105],k=1,p[105][105],number,lie=1;
	cin>>n>>m;
	w=n*m;
	for(int i=1;i<=w;i++){
		cin>>num[i];
		if(i==1){
			number=num[i];
		}
	}
	sort(num+1,num+w+1,cmp);
	while(w>k){
		if(lie%2!=0){
			for(int j=1;j<=n;j++){
				p[j][lie]=num[k];
				if(num[k]==number){
					cout<<lie<<" "<<j;
					return 0;
				}
				k++;
			}
			lie++;
		}
		if(lie%2==0){
			for(int j=n;j>=1;j--){
				p[j][lie]=num[k];
				if(num[k]==number){
					cout<<lie<<" "<<j;
					return 0;
				}
				k++;
			}
			lie++;
		}
	}
	return 0;
}
