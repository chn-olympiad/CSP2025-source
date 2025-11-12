#include<bits/stdc++.h>
using namespace std;


bool cmp(int a,int b){return a>b;}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	int l[5005];for(int i=0;i<n;i++)cin>>l[i];
	int s[5005]={};
	int a=0;
	for(int i=3;i<=n;i++){
		for(int j=0;j<i;j++)s[j]=j;
		while(s[0]<n-i+1){
			//for(int j=0;j<i;j++)cout<<s[j]<<' ';cout<<endl;	
			int x=0;
			for(int j=0;j<i;j++)x += l[s[j]];
			int m=0;
			for(int j=0;j<i;j++)m=max(m,l[s[j]]);
			m*=2;
			if(x>m)a++;
			s[i-1]++;
			for(int j=i-1;j>0;j--){
				if(s[j]>=n-(i-j-1)){
					s[j-1]++;
				}
			}
			for(int j=1;j<i;j++){
				if(s[j]>=n-(i-j-1)){
					s[j]=s[j-1]+1;
				}
			}
		}
	}
	cout<<a;
	return 0;
}
