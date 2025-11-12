#include<bits/stdc++.h> 
int  main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	
	int n,j[n];
	std::cin>>n;
	int a,b,c;
	b=c=a=n/3;
	if(n%3==1){
		a=a+1;
	}
	for(int i=0;i<=n;i++){
		j[n-i]=n*i;
		if(i==n){
			std::cout<<j[n-i]/n;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
