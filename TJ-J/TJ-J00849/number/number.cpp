#include<bits/stdc++.h>
using namespace std;
int mx=0,flag1,flag2,flag3;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string d,b;
	cin>>d;
	if(d.size()==1){
		cout<<d;
		return 0;
	}
	else if(d.size()==2){
		if(d[0]=='0'||d[0]=='1'||d[0]=='2'||d[0]=='3'||d[0]=='4'||d[0]=='5'||d[0]=='6'||d[0]=='7'||d[0]=='8'||d[0]=='9'){
			flag1=1;
		}
		if(d[1]=='0'||d[1]=='1'||d[1]=='2'||d[1]=='3'||d[1]=='4'||d[1]=='5'||d[1]=='6'||d[1]=='7'||d[1]=='8'||d[1]=='9'){
			flag2=1;
		}
		if(flag1==1&&flag2==1){
			if(int(d[0])>int(d[1])){
				cout<<d;
			}
			else{
				cout<<d[1]<<d[0];
			}
			return 0;
		}
		else if(flag1==0&&flag2==1){
			cout<<d[1];
			return 0;
		} 
		else if(flag1==1&&flag2==0){
			cout<<d[0];
			return 0;
		}	
	}
	else if(d.size()==3){
		for(int i=0;i<d.size();i++){
			if(d[i]=='0'||d[i]=='1'||d[i]=='2'||d[i]=='3'||d[i]=='4'||d[i]=='5'||d[i]=='6'||d[i]=='7'||d[i]=='8'||d[i]=='9'){
				b[i]=d[i];
			}
		}
		for(int i=0;i<b.size();i++){
			for(int j=0;j<b.size();j++){
				if(int(b[j])>mx){
					mx=int(b[j]);
					cout<<mx;
				}
			}
		}
		
		return 0;
	} 
	for(int i=0;i<d.size();i++){
		if(d[i]=='0'||d[i]=='1'||d[i]=='2'||d[i]=='3'||d[i]=='4'||d[i]=='5'||d[i]=='6'||d[i]=='7'||d[i]=='8'||d[i]=='9'){
			b[i]=d[i];
		}
	}
	for(int i=0;i<b.size()-1;i++){
		for(int j=0;j<b.size()-1;j++){
			if(int(b[j])<int(b[j+1])){
				swap(b[j],b[j+1]);
			}
		}
	}
	for(int i=0;i<b.size();i++){
		cout<<b[i];
	}
	return 0;
}
