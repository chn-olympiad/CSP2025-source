 	#include <bits/stdc++.h> 
	#include <cstdio>
	using namespace std
	int main{
		int n;
		int club[100];
		int maxx[100];
		int popl[100];
		int fl[100];
		cin >> n;
		cin >> club;
		freopen("club.in","r",stdin);
	 	freopen("club.out","w",stdout);
		for(int j=0;j<n;j++){
		for(int i=0;i<3;i++){
			if (club[i]>maxx){
				maxx[j]=club[i];
				popl[j]=i;
			}
		}
		}
		for(int p=0;p<3;p++){
			if(popl[p]=2){
				fl[2]+=1;
			}
			if(popl[p]=1){
				fl[1]+=1;
			}
			if(popl[p]=0){
				fl[0]+=1;
			}
		}
		cout <<popl;
	freclose(stdin);
	freclose(stdout);	
	return 0
	}
