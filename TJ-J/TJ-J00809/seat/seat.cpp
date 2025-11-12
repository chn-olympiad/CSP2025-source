#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	vector<int>a(n*m);
	for(int i=0;i<n*m;i++)cin>>a[i];
	
	int tar=a[0];
	sort(a.begin(),a.end(),greater<int>());
	
	int idx=0;
	for(int i=0;i<n*m;i++){
		if(a[i]==tar){
			idx=i;
			break;	
		}
	}
	idx++;
//	cout<<idx<<"\n";
	int ct=0;
	for(int i=0;i<n;i++){
		if(i&1){//向上 
			for(int j=m-1;j>=0;j--){
				ct++;
//				cout<<"向上：：ct"<<ct<<"\n"; 
				if(ct==idx){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}	
		}else{//向下 
			for(int j=0;j<m;j++){
				ct++;
//				cout<<"向xia：：ct为："<<ct<<"\n"; 
				if(ct==idx){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
