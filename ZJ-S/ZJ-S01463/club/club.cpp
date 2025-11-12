#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int club,val,g1,g2,g3;
}ren[100000];
int a[1000010][4];
void zy(int i,int club){
	//cout << "zhuanyi==="<<i<<" : "<<ren[i].club;
	ren[i].club = club;
	ren[i].val = a[i][club];
	ren[i].g1 = ren[i].val - a[i][1];
	ren[i].g2 = ren[i].val - a[i][2];
	ren[i].g3 = ren[i].val - a[i][3];
	//cout <<"->"<<ren[i].club<< endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	int club[10000][4];
	for(int hj = 0;hj < t;hj++){
		cin >> n;
		memset(ren,0,sizeof(ren));
		for(int i = 1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		int sum = 0;
		int mr = n/2;
		int c1 = 0,c2 = 0,c3 = 0;
		ren[-1].g1 = 9999999;
		ren[-1].g2 = 9999999;
		ren[-1].g3 = 9999999;
		for(int i = 1;i <= n;i++){
			//cout << "i="<<i<<endl;
			if(a[i][1] > a[i][2]&&a[i][1] > a[i][3]){
				//cout << "1" <<endl;
				zy(i,1);
				//cout << ren[i].val << endl;
				if(c1 == mr){
					if(c2 == mr){
						int j = -1;
						for(int o = 1;o < i;o++){
							if(ren[o].club == ren[i].club){
								if(ren[o].g3 < ren[j].g3){
									j = o;
								}
							}
						}
						if(ren[j].g3 < ren[i].g3){
							zy(j,3);
							c3++;
						}else{
							zy(i,3);
							c3++;
						}
					}else if(c3 == mr){
						int j = -1;
						for(int o = 1;o < i;o++){
							if(ren[o].club == ren[i].club){
								if(ren[o].g2 < ren[j].g2){
									j = o;
								}
							}
						}
						if(ren[j].g2 < ren[i].g2){
							zy(j,2);
							c2++;
						}else{
							zy(i,2);
							c2++;
						}
					}else{
						//cout <<"lll"<<endl;
						int j = -1;
						for(int o = 1;o < i;o++){
							//cout <<ren[o].club<<endl;
							//cout <<ren[i].club<<endl;
							if(ren[o].club == ren[i].club){
								if(min(ren[o].g2,ren[o].g3) < min(ren[j].g2,ren[j].g3)){
									j = o;
								}
							}
						}
						//cout << j <<endl;
						int wherej,wherei;
						if(ren[j].g2 < ren[j].g3){
							wherej = 2;
						}else{
							wherej = 3;
						}
						if(ren[i].g2 < ren[i].g3){
							wherei = 2;
						}else{
							wherei = 3;
						}
						if(min(ren[j].g2,ren[j].g3) < min(ren[i].g2,ren[i].g3)){
							zy(j,wherej);
							if(wherej = 2)c2++;
							if(wherej = 3)c3++;
						}else{
							zy(i,wherei);
							if(wherei = 2)c2++;
							if(wherei = 3)c3++;
						}
					}
				}else{
					c1++;
				}
			}else if(a[i][2] > a[i][3]){
				//cout << "2" <<endl;
				zy(i,2);
				//cout << ren[i].val << endl;
				if(c2 == mr){
					//cout << "12321zhuan" << endl;
					if(c1 == mr){
						int j = -1;
						//cout << ren[j].club <<"->j   i<-"<< ren[i].club<<endl;
						for(int o = 1;o < i;o++){
							//cout << ren[o].club <<"->o   i<-"<< ren[i].club<<endl;
							if(ren[o].club == ren[i].club){
								if(ren[o].g3 < ren[j].g3){
									
									j = o;
								}
							}
						}
						if(ren[j].g3 < ren[i].g3){
							zy(j,3);
							c3++;
						}else{
							zy(i,3);
							c3++;
						}
					}else if(c3 == mr){
						int j = -1;
						for(int o = 1;o < i;o++){
							if(ren[o].club == ren[i].club){
								if(ren[o].g1 < ren[j].g1){
									j = o;
								}
							}
						}
						if(ren[j].g1 < ren[i].g1){
							zy(j,1);
							c1++;
						}else{
							zy(i,1);
							c1++;
						}
					}else{
						int j = -1;
						for(int o = 1;o < i;o++){
							//cout << ren[o].club <<"  o:  "<<o<<" i<-"<< ren[i].club<<endl;
							if(ren[o].club == ren[i].club){
								if(min(ren[o].g1,ren[o].g3) < min(ren[j].g1,ren[j].g3)){
									j = o;
								}
							}
						}
						if(j != -1){
							int wherej,wherei;
							if(ren[j].g1 < ren[j].g3){
								wherej = 1;
							}else{
								wherej = 3;
							}
							if(ren[i].g1 < ren[i].g3){
								wherei = 1;
							}else{
								wherei = 3;
							}
							if(min(ren[j].g1,ren[j].g3) < min(ren[i].g1,ren[i].g3)){
								zy(j,wherej);
								if(wherej = 1)c1++;
								if(wherej = 3)c3++;
							}else{
								zy(i,wherei);
								if(wherei = 1)c1++;
								if(wherei = 3)c3++;
							}	
						}	
					}
				}else{
					c2++;
				}
			}else{
				//cout << "3" <<endl;
				zy(i,3);
				//cout << ren[i].val << endl;
				if(c3 == mr){
					if(c1 == mr){
						int j = -1;
						for(int o = 1;o < i;o++){
							if(ren[o].club == ren[i].club){
								if(ren[o].g2 < ren[j].g2){
									j = o;
								}
							}
						}
						if(ren[j].g2 < ren[i].g2){
							zy(j,2);
							c2++;
						}else{
							zy(i,2);
							c2++;
						}
					}else if(c2 == mr){
						int j = -1;
						for(int o = 1;o < i;o++){
							if(ren[o].club == ren[i].club){
								if(ren[o].g1 < ren[j].g1){
									j = o;
								}
							}
						}
						if(ren[j].g1 < ren[i].g1){
							zy(j,1);
							c1++;
						}else{
							zy(i,1);
							c1++;
						}
					}else{
						int j = -1;
						for(int o = 1;o < i;o++){
							if(ren[o].club == ren[i].club){
								if(min(ren[o].g1,ren[o].g2) < min(ren[j].g1,ren[j].g2)){
									j = o;
								}
							}
						}
						int wherej,wherei;
						if(ren[j].g1 < ren[j].g2){
							wherej = 1;
						}else{
							wherej = 2;
						}
						if(ren[i].g1 < ren[i].g2){
							wherei = 1;
						}else{
							wherei = 2;
						}
						if(min(ren[j].g1,ren[j].g3) < min(ren[i].g1,ren[i].g3)){
							zy(j,wherej);
							if(wherej = 1)c1++;
							if(wherej = 2)c2++;
						}else{
							zy(i,wherei);
							if(wherei = 1)c1++;
							if(wherei = 2)c2++;
						}
					}
				}else{
					c3++;
				}
			}
		}
		for(int i = 1;i <= n;i++){
			sum+=ren[i].val;
			//cout <<"i="<<i<<"=="<< ren[i].val << endl;
		}
		cout << sum << endl;
	}
	return 0;
}
