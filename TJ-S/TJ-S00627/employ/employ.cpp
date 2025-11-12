#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[n];
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=i*(i-1)/2;i++){
		for(int j=0;j<n;j++){
			if(b[i]>b[i+1])
			{
				int sum=b[i];
				b[i]=b[i+1];
				b[i+1]=sum;
			}
		}
	}
	int x=0;
	for(int j=1,k=1;j<=n;k++)
	{	
	int ans=0,w=0;
		if(k==n){
			j++;
			k=j;
		}
		int sum=b[j];
		b[j]=b[k];
		b[k]=sum;
		for(int i=0;i<n;i++){
		if(ans==m){
			x++;
			break;
		}
		char c=s[i];
		if(c=='0'){
			w++;
		}
		else{
			if(b[i]>w&&c=='1'){
				ans++;
			}	
		}
	}
	int mus=b[k];
	b[k]=b[j];
	b[j]=b[k];
	}
	cout<<x;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
