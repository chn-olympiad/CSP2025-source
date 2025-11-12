#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen (" seat .in","r",stdin);
	freopen (" seat .out","w",stdout);
	long long  n,m;
	cin>>n>>m;
	int num=0;
	int arr_2[n*m];
	for(int  i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr_2[j];
			if(i==0 and j==0) num=arr_2[j];
		}
	}
	for(int i=0;i<n*m-1;i++){
		for(int j=0;j<m*n-1;j++){
			if(arr_2[j]>arr_2[j+1]){
				swap(arr_2[j],arr_2[j+1]);
			}
		}
	}
	
	int num_2=0;
	 
	for (int i=0;i<n*m;i++){
		if(num==arr_2[i]){
			num_2=i;
		}
	}
	cout<<num_2/n<<' '<<num_2%n;
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
