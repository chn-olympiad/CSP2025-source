#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,z,jishu=0;
	cin>>n>>z;
	int arr[n]={0};
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int cnt=0;
			for(int k=i;k<=j;k++){
				cnt=arr[k]^cnt;
				if(cnt>z){
					break;
				}
			}
			if(cnt==z){
				jishu++;
			}
		}
		
	}
	cout<<jishu;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
