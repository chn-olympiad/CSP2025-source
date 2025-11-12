#include<bits/stdc++.h>
using namespace std;
string a[1000005],b[1000005][2],m[1000005];
int main(){
	int n,q;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<q;i++){
		cin>>b[i][0]>>b[i][1];
	}
	for(int i=0;i<q;i++)
		for(int w=1;w<a[i].size();w++)
			for(int l=0,r=l+w;l<a[i].size()-w;l++)
				for(int k=0;k<n;k++){
					if(a[k].size()==w)
						for(int j=l;j<r;j++)
							b[i][0][j]=a[k][j-l];
					if(b[i][0]==b[i][1])m[i]+=1;
				}
	for(int i=0;i<q;i++)cout<<m[i];
	return 0;
}