//#Shang4Shan3Ruo6Shui4
//2
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,s1,wei=1,x=1,y=1;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<n*m;i++){
		cin>>s1;
		if(s1>s)wei++;
	}
	for(int i=1;i<wei;i++){
		if(x%2==1){
			if(y==n)x++;
			else y++;
		}
		else{
			if(y==1)x++;
			else y--;
		}
	}	
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
