#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],s[505],df,ea;
char ch;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		if(ch=='0'){
			df++;
			c[i]=0;
		}else{
			ea++;
			c[i]=1;
		}
	}
	if(ea<=m){
		cout<<0<<endl;
		return 0;
	}
	bool bb;
	int i;
	for(i=n;i>0;i--)if(s[i]==1)break;
	if(i+df==n)bb=true;
	else bb=0;
	if(m==1||ea==n||bb){
		int sum=1;
		for(int i=2;i<=n;i++)sum=sum*i%998244353;
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

