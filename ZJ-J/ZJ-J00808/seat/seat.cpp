#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N=105;
int n,m;
int a[N][N];
int b[N*N];
int idx;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	
	idx=b[1];
	sort(b+1,b+n*m+1,greater<int>());
	
//	for(int i=1;i<=n*m;i++){
//		cout<<b[i]<<" ";
//	}cout<<"\n";
	
	if(b[1]==idx){
		cout<<"1 1\n";
		return 0;
	}
	
	int i=1,j=1,k=1;
	while(i<=n&&j<=m){
		if(j%2){
			i++;
			a[i][j]=b[++k];
		}
		else{
			i--;
			a[i][j]=b[++k];
		}
		
		if(a[i][j]==idx){
			cout<<j<<" "<<i<<"\n";
			return 0;
//			break;
		}
		
		if((i==1||i==n)&&j<m){
			j++;
			a[i][j]=b[++k];
			if(a[i][j]==idx){
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		}
	}
	return 0;
}

/*
2 2
99 100 97 98
*/
