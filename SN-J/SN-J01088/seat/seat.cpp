#include<bits/stdc++.h>
using namespace std;
int n,m,chengji[100100100];
int cj,sum=1;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	cin>>chengji[i];
	
	cj=chengji[0];
	
	sort(chengji,chengji+n*m);
	
	for(int i=n*m-1;chengji[i]!=cj;i--)
	{
		sum++;
		if(chengji[i]==cj) break;
	}
	cout<<m/sum+1<<" "<<n%sum;
	
	return 0;
}
/*
2 2
98 99 100 97
*/
