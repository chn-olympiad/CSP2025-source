#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int a,max=0,cnt=0,length=0;
	cin >> a;
	int num[a];
	for(int i=0;i<a;i++){
		cin >>num[i];
	} 
	for(int i=0;i<a;i++){
		if(num[i]>max){
			max=num[i];
		}
	}
	if(a==3){
		if(num[0]+num[1]+num[2]>max*2){
			cnt++;
		}
	}
	else if(a==4){
		if(num[0]+num[3]+num[2]+num[1]>max*2){
			cnt++;
		}
		if(num[0]+num[1]+num[2]>max*2){
			cnt++;
		}
		if(num[0]+num[1]+num[3]>max*2){
			cnt++;
		}
		if(num[0]+num[3]+num[2]>max*2){
			cnt++;
		}
		if(num[1]+num[3]+num[2]>max*2){
			cnt++;
		}
	}
	cout << cnt <<endl;
	return 0;
}
