#include<bits/stdc++.h>
using namespace std;
int a[500005][20],now[20],kd[20];
int n,k,sum;

int co(int x[20],int y[20]){
	for(int i=20;i>0;i--){
		if(x[i]%2==1&&y[i]==0)return 3;
		if(x[i]%2==0&&y[i]==1)return 1;
	}
	return 2;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=20;i++){
		if(k<=0)break;
		kd[i]=k%2;
		k/=2;
	}
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=20;j++){
			if(x<=0)break;
			a[i][j]=x%2;
			x/=2;
		}
	}
	
	int st=1,cp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=20;j++)now[j]+=a[i][j];
		cp=co(now,kd);
		while(cp==3){
			for(int j=1;j<=20;j++){
				now[j]-=a[st][j];
			}
			st++;
			cp=co(now,kd);
		}
		if(cp==2&&st<=i){
			memset(now,0,20);
			sum++;
			st=i+1;
		}
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
