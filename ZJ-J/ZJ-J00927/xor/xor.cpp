#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	vector<int>s(n+5);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x==m)sum++,s[i]=-1;
		else{
			if(s[i-1]==-1||i==1)s[i]=x;
			else s[i]=s[i-1]^x;
			if(s[i]==m){
				for(int j=i;j>=1;j--){
					if(s[j]==-1)break;
					s[j]=-1;
				}
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
