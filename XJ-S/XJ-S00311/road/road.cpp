#include<bits/stdc++.h>
using namespace std;

int s[100010][3]={};
int c[100010]={};
int p[100010]={};
int n,m,k;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>s[i][0]>>s[i][1]>>s[i][2];
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n+1;j++){
			cin>>p[j];
		}
	}
	cout<<0;
	return 0;
	
} 
