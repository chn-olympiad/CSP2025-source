#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int sum=0;
	int all=0;
	int max=0;
	for(int i=0;i<n;i++){
		if(v[i]>max){
			max=v[i];
		}
	} 
	for(int i=0;i<n;i++){
		int flag=0;
		for(int j=i;j<n;j++){
			all+=v[j];
			flag++;
			if(flag>=3 and all/2>max){
				sum++;
			}
		}
		all=0;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
