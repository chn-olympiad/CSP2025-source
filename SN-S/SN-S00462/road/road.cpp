#include<bits/stdc++.h>
using namespace std;
int a[100001]={},b[100001]={},c[100001]={};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0,t=3,q=0;
	cin>>n>>m>>k;
	for(int i=0;i<m*3;i++){
		cin>>a[i];
		if(i==t-1){
			c[q]=a[i];
			q++;
			t=t+3;
		}
	}
	for(int j=0;j<k*(n+1);j++){
		cin>>b[j];
	}
	sort(c,c+n);
	sum=c[0]+c[1]+c[2]+c[3];
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

