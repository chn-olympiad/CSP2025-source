#include<bits/stdc++.h>
using namespace std;
int n,m,score[120]={};
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>score[i];
	}
	sort(score.begin(),score.end());
	
	return 0;
}
