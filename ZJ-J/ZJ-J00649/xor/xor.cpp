#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],cnt;
bool check(int x,int y){
	int cnt=0;
//	if(x==2&&y==4)cout<<cnt<<endl;
	for(int i=x;i<=y;i++){
		if(b[i])return false;
		cnt^=a[i];
	}
//	if(x==2&&y==4)cout<<cnt<<endl;
	return cnt==k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){//区间长度
		for(int j=1;j<=n-i+1;j++){//start
		//i=3,j=2:
	//		if(i==3&&j==2)cout<<"check:\n";
			if(check(j,j+i-1)){
				cnt++;
			//	cout<<j<<' '<<j+i-1<<endl;
				for(int k=j;k<=j+i-1;k++)b[k]=1;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
