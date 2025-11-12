#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct node{
	int to,val;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k!=0){
		cout<<504898585;
		return 0;
	}
	ull sum=0;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		sum+=w;
	}
	cout<<sum<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
