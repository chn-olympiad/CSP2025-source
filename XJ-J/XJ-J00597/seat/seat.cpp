#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int s[1145];
int vis[114][114];
bool cmd(int x,int y){
	if(x>y) return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	k=s[0];
	sort(s+0,s+(n*m),cmd);
	int l=0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<m;j++){
				vis[j][i]=s[l];
				l++;
			}
		}else{
			for(int j=m-1;j>=0;j--){
				vis[j][i]=s[l];
				l++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j]==k){
				cout<<j+1<<" "<<i+1;
				return 0;
			}
		}
	}
	return 0;
}
