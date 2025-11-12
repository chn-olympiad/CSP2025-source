#include<bits/stdc++.h>
using namespace std;

bool Have_A=1;

int A_arr[100007];
int arr[10][100007];
int t;

bool cmpa(int vadd,int vbdd){
	return vadd>vbdd;
}

int sloveA(int len){
	int ans=0;
	sort(A_arr+1,A_arr+1+len,cmpa);
	for(int i=1;i<=len/2;i++)ans+=A_arr[i];
	return ans;
}
int cnt;
void dfs(int A_club,int B_club,int C_club,int index,int sum,int MAX){
	if(A_club>MAX/2 || B_club>MAX/2 || C_club>MAX/2)return;
	if((A_club+B_club+C_club)!=MAX && index==MAX+1)return;
	if(index==MAX+1){
		cnt=max(sum,cnt);
		return;
	}
	for(int i=index;i<=MAX;i++){
		dfs(A_club+1,B_club,C_club,i+1,sum+arr[1][i],MAX);
		dfs(A_club,B_club+1,C_club,i+1,sum+arr[2][i],MAX);
		dfs(A_club,B_club,C_club+1,i+1,sum+arr[3][i],MAX);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(A_arr,0,sizeof(A_arr));
		memset(arr,0,sizeof(arr));
		cnt=0;Have_A=1;
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[1][i]>>arr[2][i]>>arr[3][i];
			if(arr[2][i]||arr[3][i])Have_A=0;
			if(Have_A)A_arr[i]=arr[1][i];
		}
		if(Have_A)cout<<sloveA(n)<<'\n';
		else{
			dfs(0,0,0,1,0,n);
			cout<<cnt<<'\n';
		}
	}
	return 0;
}
