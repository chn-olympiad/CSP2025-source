#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	ifstream infile("club.in");
	if(infile){
		infile>>t;
		int result[t];
		for(int num=0;num<t;num++){
			int n;
			infile>>n;
			int nownum=n;
			int a[n][3];
			for(int i=0;i<n;i++){
				infile>>a[i][0];
				infile>>a[i][1];
				infile>>a[i][2];
			}
			int group1=n/2,group2=n/2,group3=n/2,w=0;
			bool can[n],clear1=true,clear2=true,clear3=true;
			for(int i=0;i<n;i++){
				can[i]=true;
			}
			while(nownum>0){
				if(group1==0 and clear1){
					for(int i=0;i<n;i++){
						a[i][0]=-1;
						clear1=false;
					}
				}
				if(group2==0 and clear2){
					for(int i=0;i<n;i++){
						a[i][1]=-1;
						clear2=false;
					}
				}
				if(group3==0 and clear3){
					for(int i=0;i<n;i++){
						a[i][2]=-1;
						clear3=false;
					}
				}
				int pos=0,maxkey[n],maxnum=0,temp;
				for(int i=0;i<n;i++){
					if(!can[i]){
						continue;
					}
					temp=max(max(a[i][0],a[i][1]),a[i][2]);
					if(temp>maxnum){
						maxnum=temp;
						maxkey[0]=i;
						pos=0;
					}else{
						if(temp==maxnum){
							pos++;
							maxkey[pos]=i;
						}
					}
				}
				if(pos<min(min(group1,group2),group3)){
					nownum-=pos+1;
					w+=maxnum*(pos+1);
					for(int i=0;i<=pos;i++){
						can[i]=false;
						if(a[i][0]==maxnum){
							group1--;
							continue;
						}
						if(a[i][1]==maxnum){
							group2--;
							continue;
						}
						if(a[i][2]==maxnum){
							group3--;
							continue;
						}
					}
				}else{
					int pos=0,minkey[pos+1],minnum=0;
					for(int i=0;i<pos+1;i++){
						int temp[3]={a[maxkey[i]][0],a[maxkey[i]][1],a[maxkey[i]][2]};
						sort(temp,temp+3);
						if(temp[1]<minnum){
							minnum=temp[1];
							minkey[0]=maxkey[i];
							pos=0;
						}else{
							if(temp[1]==minnum){
								pos++;
								minkey[pos]=maxkey[i];
							}
						}
					}
					if(pos+1<=min(min(group1,group2),group3)){
						nownum-=pos+1;
						w+=maxnum*(pos+1);
						for(int i=0;i<=pos;i++){
							can[minkey[i]]=false;
							if(a[minkey[i]][0]==maxnum){
								group1--;
								continue;
							}
							if(a[minkey[i]][1]==maxnum){
								group2--;
								continue;
							}
							if(a[minkey[i]][2]==maxnum){
								group3--;
								continue;
							}
						}
					}else{
						int pos=0,minkey2[n],minnum2=0,temp;
						for(int i=0;i<n;i++){
							if(!can){
								continue;
							}
							temp=min(min(a[minkey[i]][0],a[minkey[i]][1]),a[minkey[i]][2]);
							if(temp>minnum2){
								minnum2=temp;
								minkey2[0]=minkey[i];
								pos=0;
							}else{
								if(temp==minnum2){
									pos++;
									minkey2[pos]=minkey[i];
								}
							}
						}
						for(int i=0;i<=pos;i++){
							if(maxnum==0){
								nownum=0;
								break;
							}		
							can[minkey2[i]]=false;
							if(a[minkey2[i]][0]==maxnum and group1>0){
								group1--;
								nownum--;
								w+=maxnum;
								continue;
							}
							if(a[minkey2[i]][1]==maxnum and group2>0){
								group2--;
								nownum--;
								w+=maxnum;
								continue;
							}
							if(a[minkey2[i]][2]==maxnum and group3>0){
								group3--;
								nownum--;
								w+=maxnum;
								continue;
							}		
						}
					}
				}
			}
			result[num]=w;
		}
		infile.close();
		ofstream outfile("club.out");
		outfile<<result[0];
		for(int i=1;i<t;i++){
			outfile<<"\n"<<result[i];
		}
		outfile.close();
		return 0;
	}
}
