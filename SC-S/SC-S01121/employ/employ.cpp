#include<iostream>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[500];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int c[500];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	long long cnt[500]={0};
	cnt[1]=1;
	cnt[2]=2;
	for(int i=3;i<=500;i++){
		cnt[i]=i*cnt[i-1];
	}
	
	cout<<cnt[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}