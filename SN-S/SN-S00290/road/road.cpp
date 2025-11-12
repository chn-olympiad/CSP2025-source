#include<iostream>
using namespace std;
#include<fstream>

int main(){
	std::ifstream cin("road.in");
	std::ofstream cout("road.out");
	int city,road,side;
	cin>>city>>road>>side;
	int fee1[city][city]={0};
	int fee2[side][city]={0};
	bool lu[city][city]=0;
	
	for(int i=1;i<=road;i++){
		int a,b,c;
		cin>>a>>b>>c;
		fee1[a][b]=c;
		lu[a][b]=1;
	} 
	for(int r=1;r<=side;r++){
		int h;
		cin>>h;
		fee2[r][0]=h;
		for(int t=1;t<=city;t++){
		int e=0;
		cin>>e;
		fee2[r][t]=e;}
			} 
	int total=0;
	int lian=0;
	for(int p=city;p<=city+side;p++){
		for(int z=1;z<p;z++){
			//路数=节点数-1
			if(p==city) {
				
			}
			
		}
	}
	
	
	
	
	return 0;
	}
