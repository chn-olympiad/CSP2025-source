#include<bits/stdc++.h>
// I am Zha4 Pian4 Fan4,my code is ZJ-J01464 
//wo3 yao4 shang4 mi2 huo4 xing2 wei2 da4 shang3
using namespace std;
//9:44~9:57 ,maybe AC in 1,2,3,4,5,13,hope score 30
int arr[500010];
int main(){
	//freopen("xor.in","r",stdin);  xro  oxr rox
	//freopen("xor.out","W",stdout); feropen() froepen() frepoen() freoepn() feropne() rfeopen()
	freopen("xor.in","r",stdin);
	freopen("xor.out","W",stdout);
	int One_sum=0;int Zero_sum=0;
	int n;
	cin>>n;
	int k;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]==1){
			One_sum++;
		}
		if(arr[i]==0){
			Zero_sum++;
		}
		
	}
	if(k==0){
		cout<<One_sum/2+Zero_sum;
		return 0;
	}
	if(k==1){
		cout<<One_sum;
		return 0;
	}
	return 0;
}
