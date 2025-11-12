#include<bits/stdc++.h>
using namespace std;
int n,t,maxx=-1,num=0;
int a[500001][3]={0};
int b[4]={0};
void df(int c){
	if(c>n){
		maxx=max(maxx,num);
		return;
	}
	for(int i=1;i<=3;i++){
		if(b[i]==0){
			continue;
		}
		b[i]-=1;
		num+=a[c][i];
		df(c+1);
		num-=a[c][i];
		b[i]+=1;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int x=1;x<=t;x++){
		maxx=0;
		num=0;
		cin>>n;
		b[1]=n/2;
		b[2]=n/2;
		b[3]=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		df(1);
		cout<<maxx<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
