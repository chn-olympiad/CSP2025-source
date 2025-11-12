#include<bits/stdc++.h>
#define ll long long
using namespace std;
int nums[10];
char a[1000006];
int main(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<1000000;i++){
		if(a[i]=='0')nums[0]++;
		if(a[i]=='1')nums[1]++;
		if(a[i]=='2')nums[2]++;
		if(a[i]=='3')nums[3]++;
		if(a[i]=='4')nums[4]++;
		if(a[i]=='5')nums[5]++;
		if(a[i]=='6')nums[6]++;
		if(a[i]=='7')nums[7]++;
		if(a[i]=='8')nums[8]++;
		if(a[i]=='9')nums[9]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=nums[i];j++)cout<<i; 
	}
}

