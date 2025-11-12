#include<bits/stdc++.h>
using namespace std;
char a[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	int n,m,cnt=0;
	cin>>n>>m;
	cin>>a;
	bool pd=true;

	for(int i=1;i<=n;i++){
		if(a[i]==1){
			cnt++;
		}else{
			pd=false;
		}
	}if(cnt<m){
		cout<<0;
	}else if(m==n){
		cout<<0;
	}else{
		cout<<1;
	}return 0; 
}
