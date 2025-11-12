#include <bits/stdc++.h>
using namespace std;
int n,q,cha;
char ns[200005][3][5000005],qs[200005][3][5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n;
	for(int i = 1;i<= n;i++){
		cin>>ns[i][1]>>ns[i][2];
	}
	while(q--){
		cin>>qs[q][1]>>qs[q][2];
		long long sum = 0;
		int len = strlen(qs[q][1]);
		cha=6000000;
		int lencha;
		for(int i = 0;i<len;i++){
			if(qs[q][1][i]!=qs[q][2][i]){
				if(cha==6000000){
					cha=i;
				}
				lencha = i-cha+1;
			}
		}
		for(int i = 1;i<= n;i++)
		{
			int k = 0;
			for(int j = 0;j<strlen(qs[q][1]);j++){
				if(k==lencha){
					k=0;
					for(int l = 0;l<strlen(qs[q][2]);l++){
						if(ns[i][2][k]==qs[q][2][l]){
							k++;
						} 
						else
						{
							k=0;
						}
						if(k==lencha){
							sum++;
							break;
						}
					}
					k=0;
				}
				if(ns[i][1][k]==qs[q][1][j]){
					k++;
				} 
				else
				{
					k=0;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
