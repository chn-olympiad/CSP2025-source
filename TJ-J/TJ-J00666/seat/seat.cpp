#include <bits/stdc++.h>
using namespace std;
long long s[105],n,m,x=1,y=1,a,b;
int main(){
	//我***讨厌排考场号，好神经的题目，你排考场号管我什么事，还让我算，**** 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	a=s[1];
	//cout<<a;
	for(int i=1;i<=m*n;i++){
		for(int j=1;j<=m*n;j++){
			if(s[j]<s[j+1]){
				int c=0,d=0;
				c=s[j];
				d=s[j+1];
				s[j]=d;
				s[j+1]=c;
				
			}
			
		}
		//cout<<s[i]<<" ";
		if(s[i]==a) b=i;
	}
	for(int i=1;i<=m*n;i++){
		if(i>n){
			y=1;
			//哎呦我不行了，还蛇形排列，xy还不好弄，*****谁出的题啊啊啊啊啊 
		}
		if(i==b){
				cout<<x<<" "<<y;
			}
	}
	return 0;
}
