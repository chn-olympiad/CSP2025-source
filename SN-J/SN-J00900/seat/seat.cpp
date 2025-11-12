//SN-J00900 胡志豪 汉滨区汉滨初级中学  
#include<bits/stdc++.h>

int a[105];
int zhao(int n,int l,int r){
	for(int i=l;i<=r;i++){
		if(a[i]==n)return i;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,exam,k;
	std::cin>>n>>m;
	std::cin>>a[0];
	exam=a[0];
	for(int i=1;i<n*m;i++)std::cin>>a[i];
	sort(a,a+n*m,std::greater<int>());
	k=zhao(exam,0,n*m-1);
	
	int ans2,ans1=k/n+1;
	if(ans1%2==0)ans2=n+1-(k%n+1);
	else ans2=k%n+1;
	std::cout<<ans1<<" "<<ans2;
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
