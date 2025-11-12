#include<iostream>
#include<cstdio>
#include<queue> 
using namespace std;
priority_queue<int> a;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int lrf;//the fenshu of little R
	for(int i=0;i<n*m;i++){
		int fenshu;
		cin>>fenshu;
		if(i==0) lrf=fenshu;
		a.push(fenshu);
	}
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<m;j++){
				if(a.top()==lrf){
					cout<<i+1<<' '<<j+1;
					return 0; 
				}else{
					a.pop();
				}
			}
		}else{
			for(int j=m-1;j>=0;j--){
				if(a.top()==lrf){
					cout<<i+1<<' '<<j+1;
					return 0;
				}else{
					a.pop();
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
