#include<bits/stdc++.h>
using namespace std;
struct hm{
	unsigned int tm[3];
	bool used[3]={false,false,false};
};
void compute(){
	ifstream cin("club.in");
	ofstream cout("club.out");
	int n;
	cin >>n;
	hm *hum=new hm[n];
	vector<hm> tm1,tm2,tm3;
	for(int i=0;i<n;i++){
		cin>>hum[i].tm[0]>>hum[i].tm[1]>>hum[i].tm[2];
		int sutm = (hum[i].tm[0]>=hum[i].tm[1]?(hum[i].tm[1]>=hum[i].tm[2]?0:(hum[i].tm[0]>=hum[i].tm[2]?0:2)):(hum[i].tm[0]>=hum[i].tm[2]?1:(hum[i].tm[1]>=hum[i].tm[2]?1:2)));
		switch (sutm) {
		case 0:
			{
				if(tm1.size()<n/2){
					tm1.push_back(hum[i]);
					hum[i].used[0]=true;
				}else if(tm2.size()<n/2&&tm3.size()<n/2){
					if(hum[i].tm[1]>hum[i].tm[2]){
						tm2.push_back(hum[i]);
						hum[i].used[1]=true;
					}else{
						tm3.push_back(hum[i]);
						hum[i].used[2]=true;
					}
				}else if(tm2.size()<n/2){
					tm2.push_back(hum[i]);
					hum[i].used[1]=true;
				}else{
					tm3.push_back(hum[i]);
					hum[i].used[2]=true;
				}
				break;
			}
		case 1:
			{
				if(tm2.size()<n/2){
					tm2.push_back(hum[i]);
					hum[i].used[0]=true;
				}else if(tm1.size()<n/2&&tm3.size()<n/2){
					if(hum[i].tm[0]>hum[i].tm[2]){
						tm1.push_back(hum[i]);
						hum[i].used[0]=true;
					}else{
						tm3.push_back(hum[i]);
						hum[i].used[2]=true;
					}
				}else if(tm1.size()<n/2){
					tm1.push_back(hum[i]);
					hum[i].used[0]=true;
				}else{
					tm3.push_back(hum[i]);
					hum[i].used[2]=true;
				}
				break;
			}
		case 2:
			{
				tm3.push_back(hum[i]);
				hum[i].used[2]=true;
				break;
			}
		default:
			break;
		}
	}
	int tot[3]={};
	for(int i=0;i<tm1.size();i++){
		tot[0]+=tm1.at(i).tm[0];
	}
	for(int i=0;i<tm2.size();i++){
		tot[1]+=tm2.at(i).tm[1];
	}
	for(int i=0;i<tm3.size();i++){
		tot[2]+=tm3.at(i).tm[2];
	}
	cout<<tot[0]+tot[1]+tot[2];
	cin.close();
	cout.close();
}
int main(){
	ifstream cin("club.in");
	int n;
	cin>>n;
	cin.close();
	for(int i=0;i<n;i++){
		compute();
	}
}
