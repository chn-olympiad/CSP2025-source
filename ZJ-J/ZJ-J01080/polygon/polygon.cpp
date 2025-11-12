#include<bits/stdc++.h>

using namespace std;
int n;
int bian[5001];int a[5001];
int dfs(int bs,int zdbh){
     int sum=0,s2=0;if(bs>n){
     	return 0;
	 }
	 if(bs>=3){
     for(int i=1;i<=bs;i++){
     	s2+=bian[i];
	 }
	 if(s2<=2*bian[bs]){
	 	return 0;
	 }else{
	 	sum++;for(int i=1;i<=bs;i++){
     	cout<<bian[i];
	 }
	 cout<<"\n";
	 }
	 }
	for(int i=zdbh+1;i<n;i++){
		bian[bs+1]=a[i];
		sum+=dfs(bs+1,i);
	}
	return sum;
}
//hegfjwhjd
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
    
    cin>>n;
    
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	sort(a,a+n);
	cout<<dfs(-1,0);
fclose(stdin);
fclose(stdout);
    return 0;
}
//you bian de hao xiang chao wo de 4 3 3 3 4 1 1 1
