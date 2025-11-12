#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a>b){
		return 1;
	}else if(a<b){
		return 0;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l;
	cin>>h>>l;
	int a[h][l];
	int ls[h*l];
	for(int i=0;i<h*l;i++)
		cin>>ls[i];
	int r1=ls[0];
	sort(ls,ls+(h*l),cmp);
	int r=0;
	for(int i=0;i<(h*l);i++){
		if(ls[i]==r1){
			r=i;
			break;
		}
	}
	int i=1,outh=1;
	for(i=1;i<=l;i++){
		if(r>=h){
			r-=h;
			continue;
		}else{
			if(r==0){
				if(i%2==0){
					outh=1;
				}else{
					outh=h;
				}
				
				break;       
			}
			if(r%2==0){
				outh=h-r+1;
				break;
			}else{
				outh=1+r;
				break;
				
			}
		}
	}
	
	cout<<outh<<" "<<i;
	return 0;
} 
