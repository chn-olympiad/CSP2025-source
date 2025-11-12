#include<bits/stdc++.h>
using namespace std;
long long n,q=0;
long long a[100000];
int dfs(int x,int he,int ge,int maxm,int bo){
	if(x>n){
		return 0;
	}	
	//;
	if(ge>=3&&he>2*maxm&&bo){
		q++;
		//cout<<x<<" "<<he<<" "<<ge<<" "<<maxm<<endl;
	}
	int y=a[x];	
	dfs(x+1,he,ge,maxm,0);	
	if(maxm<a[x]){
		maxm=a[x];
	}
	//cout<<endl;
	dfs(x+1,he+y,ge+1,maxm,1);
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	dfs(0,0,0,0,0);
	cout<<q;
	return 0;
}  
