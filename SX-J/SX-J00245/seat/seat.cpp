#include<bits/stdc++.h>
using namespace std;
int n,m;
int xiaor;
int chengji[101];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n][m];
	int nm=n*m;
	cin>>xiaor;
	chengji[1]=xiaor;
	int cnt=1;
	for(int i=2;i<=nm;i++){
		cin>>chengji[i];
		cnt++;
	}
	int rspm;
	sort(chengji+1,chengji+nm+1,cmp);
	for(int i=1;i<=nm;i++){

		if(chengji[i]==xiaor){
			rspm=i;
			break;
		}
	}
	int ansm=(rspm+n-1)/n;
	cout<<ansm<<" ";
	if(rspm%n==0){
		cout<<n;
	}else if(ansm%2==0){
		int qw=ansm-1;
		int qwe=qw*n;
		rspm=rspm-qwe;
		cout<<n-rspm+1;
	}else{
		int qw=ansm-1;
		int qwe=qw*n;
		rspm=rspm-qwe;
		cout<<rspm;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}