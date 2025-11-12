#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int>polygon(n,0);
	vector<vector<long long> >dp(n,vector<long long>(n,0));
	for(int i=0;i<n;i++){
		cin>>polygon[i];
	}
	sort(polygon.begin(),polygon.end());
	if(n==3){
		if(polygon[0]+polygon[1]>polygon[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	else{
		if(polygon[n-1]==1){
			int result=1;
			int temp=n;
			while(temp>0){
				result*=2;
				temp--;
			}
			result-=1;
			result-=n;
			result-=((n*(n-1))/2);
			cout<<result;
		}
	}
//	for(int i=3;i<n;i++){
//		
//	}
//	for(int i=3;i<n;i++){
//		for(int j=3;j<=i;j++){
//			if(2*polygon[i-1]>polygon[i])
//		}
//	}
	return 0;
}
