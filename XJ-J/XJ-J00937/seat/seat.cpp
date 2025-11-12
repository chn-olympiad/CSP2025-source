#include<bits/stdc++.h>
using namespace std;

int n,m,mc,fs,x,y;//mc为小R的名次  fs为小R的分数 
int a[200];
//a[1]为小R的成绩 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		fs=a[1];
	}
	//从小到大排序 
	sort(a+1,a+n*m+1);
	int p=1; 
	//从大到小遍历 
	for(int i=n*m;i>=1;i--){
		if(a[i]==fs){
			mc=p;
			if(mc%n==0){//单数列尾 双数列首 
				y=mc/n;
				if(y%2==0){//双数列 
					x=1;
				}else{//单数列 
					x=n;
				}
			}else{//除了单数列尾 双数列首 
				y=mc/n+1;
				if(y%2==0){//双数列 
					x=n-(mc-n*(y-1))+1;
				}else{//单数列 
					x=mc-n*(y-1);
				}
			}
			cout<<y<<" "<<x;
			break;
		}else{
			p++;
		}
	} 
	
	return 0;
} 
