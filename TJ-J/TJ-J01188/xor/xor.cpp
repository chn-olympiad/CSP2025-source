#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int xorsum(int i,int j){
	int xorsum=0;
	for(int k=i;k<=j;k++){
		xorsum=(xorsum^a[k]);
	}
	return xorsum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	vector<vector<int> > ans;
	vector<vector<int> >result;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(xorsum(i,j)==k){
				vector<int>temp(3);
				temp[0]=i;
				temp[1]=j;
				temp[2]=0;
				ans.push_back(temp);
			}
		}
		int counta=0,countr=0;
		for(int j=0;j<(int)result.size();j++){
			result[j][2]=0;
		}
		for(int j=0;j<(int)ans.size();j++){
			ans[j][2]=0;
		}
		for(int j=0;j<(int)ans.size();j++){
			for(int k=0;k<(int)result.size();k++){
				if(ans[j][0]>=result[k][0]){
					if(ans[j][0]<=result[k][1]){
						if(ans[j][2]==0){
							counta++;
							ans[j][2]=1;
						}
						if(result[k][2]==0){
							countr++;
							result[k][2]=1;
						}
					}
				}else{
					if(ans[j][1]>=result[k][0]){
						if(ans[j][2]==0){
							counta++;
							ans[j][2]=1;
						}
						if(result[k][2]==0){
							countr++;
							result[k][2]=1;
						}
					}
				}
			}
		}
		if(counta>countr){
			for(int j=0;j<(int)ans.size();j++){
				if(ans[j][2]==0){
					result.push_back(ans[j]);
				}
			}
			vector<vector<int> > temp;
			ans=temp;
		}else{
			for(int j=0;j<(int)result.size();j++){
				if(result[j][2]==0){
					ans.push_back(result[j]);
				}
			}
			vector<vector<int> > temp;
			result=ans;
			ans=temp;
		}
	}
	cout<<result.size();
	return 0;
}
