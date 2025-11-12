#include<bits/stdc++.h>
using namespace std;
int n,m,arr[101],line[]={1,2,3,4,4,3,2,1},pos;
/*
int sort1(int *arr,int len){
	int left[100],right[100],middle=*(arr+len/2),result[101];
	int li,ri;
	if(len==1||len==0){
		return arr;
	}
	for(int i=0;i<len;i++){
		if(*(arr+i)<middle){
			left[li]=*(arr+i);
			li++;
		}
		else{
			right[ri]=*(arr+i);
			ri++;	
		}
	}
	int left2[101]=sort1(left,li),right2[101]=sort1(right,ri);
	for(int i=0;i<li;i++){
		result[i]=*(left2+i);
	}
	result[li]=middle;
	for(int i=li+1;i<li+ri;i++){
	    result[i]=*(right2+i);
    }
    return result;
}
*/
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	int aaa=arr[0];
	for(int i=0;i<n*m;i++){
		int i_idx=i;
		for(int j=i+1;i<n*m;i++){
			if(arr[i_idx]<arr[j]){
				int b;
				b=arr[i_idx];
				arr[i_idx]=arr[j];
				arr[j]=b;
				i_idx=j;
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(arr[i]==aaa){
			pos=i;
			break;
		}
	}
	cout<<pos%4<<' '<<line[pos%8]<<'\n';
	return 0;
}

