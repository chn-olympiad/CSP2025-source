#include<bits/stdc++.h>
using namespace std;

int n,m,k,u,w,v,minn;
int k14=6,k23=7,k42=5,k43=4;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++){
		min(k14,k23);
		min(k23,k42);
		min(k42,k43);
		min(k14,k43);
		
	}
	minn=k43+5+1+1+2;
	cout<<minn;
	fclose(stdin);
	fclose(stdout);

	return 0;
}

