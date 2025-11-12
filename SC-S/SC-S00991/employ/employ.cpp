#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000005],l,lz,d[1000005];
int main(){
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>b[i];
		d[i]=b[i];
	}
	for(int k=0;k<n;k++){
		for(int k2=0;k2<n;k2++){
			int c=b[k];
			b[k]=b[k2];
			b[k2]=c;
			for(int i=0;i<n;i++){
				if(b[i]<=0)for(int j=i;j<n;j++)b[j]--;
				else if(s[i]=='1')
					l++;
				else
					for(int j=i;j<n;j++)b[j]--;
			}
			if(l>=m)lz++;
			l=0;
			for(int i=0;i<n;i++){
				b[i]=d[i];
			}
		}
	}
	cout<<lz;
	return 0;
}