#include<bits/stdc++.h>
using namespace std;
int n,m,xiaoR;
int lis[105];
int zzds(){
	int mp=n*m+1;
	while(mp--){
	
	for( int i=mp;i>0;i--){
		//cout<<" i"<<i<<"seff"<<lis[i]<<" "<<lis[i-1]<<endl;
		if(lis[i]>lis[i-1]){
			int ls;
			ls=lis[i-1];
			lis[i-1]=lis[i];
			lis[i]=ls;
		}
		if(lis[i]<lis[i+1]){
			int ls;
			ls=lis[i+1];
			lis[i+1]=lis[i];
			lis[i]=ls;
		}
	}
	}
	return 0;
}
int gethanglie(int iii){
	int lie=-1,hang=-1;
	if(iii%n==0){
		lie=iii/n;
		hang=n;
		//cout<<"i%n=0"<<iii<<"i< n>"<<n<<"<";
	}
	else{
		lie=iii/n+1;
		//cout<<"i%n!=0";
	}
	if(lie%2==1 && hang==-1){
		hang=iii%n;
		//cout<<"OOOOOOOOOOOOOOOOOOOO  i>>"<<iii<<"<n>>>"<<n<<endl;
	}
	
	else if(hang==-1){
		hang=n-(iii%n);
	}
	cout<<lie<<" "<<hang;
	return 0;
}
int main(){
	freopen("seat.in",r,stdin);
	freopen("seat.out",w,stdout);
	cin>>n>>m;
	cin>>xiaoR;
	lis[0]=xiaoR;
	for(int i=1;i<(n*m);i++){
		cin>>lis[i];
	}
	zzds();
	for(int i=0;i<(n*m);i++){
		//cout<<"SAR"<<i<<" "<<lis[i]<<"END"<<endl;
		if(lis[i]==xiaoR){
			gethanglie(i+1);
			return 0;
		}
	}
	return 0;
}
