#include<bits/stdc++.h>
using namespace std;
int main(){
	int q[100][100];
	int m,n;
	cin>>m>>n;
	for(int i = m*n;i>0;i--){
		for(int j = i;j>0;j--){
			cin>>q[i];
			if(q[i]>q[i+1]){
				q[i] = q[i+1];
				q[i+1] = q[i];
			}
		}
	}
	cout<<q[i][j];	
}
