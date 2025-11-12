#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],bj[510],yy=0;
string as;
void go(int i,int s,int o){
	if(i==n){
		if(s>=m){
			yy++;
			yy%=998244353;
		}
		return;
	}
	for(int j=1;j<=n;j++){
		if(bj[j]==0&&c[j]>o){
			bj[j]=1;
			if(as[i]=='1'){
				go(i+1,s+1,o);
			}else{
				go(i+1,s,o+1);
			}
			bj[j]=0;
		}else if(c[j]<=o&&bj[j]==0){
			bj[j]=1;
			go(i+1,s,o+1);
			bj[j]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>as;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	go(0,0,0);
	cout<<yy;
	return 0;
}
/*




*/
