//by snakeMC
//now:AC
#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,bool> a,pair<int,bool> b){
	return a.first>b.first;
}
int n,m;
pair<int,bool> a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].first;
	}
	a[0].second=true;
	sort(a,a+n*m,cmp);
	int cnt=0;
	while(1){
		if(a[cnt].second)break;
		else cnt++;
	}
	int lie=cnt/n,h=(lie&1) ? n-1-(cnt-lie*n) : cnt-lie*n ;
	cout<<lie+1<<" "<<h+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
