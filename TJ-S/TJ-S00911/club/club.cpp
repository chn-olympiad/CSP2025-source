#include <bits/stdc++.h>
using namespace std;
int t,n,maxc;
struct node{
	int fi,se,th;//1，2，3社团满意度 
	int maxm;//最满意的社团  
	bool vis;
}stu[100005];
int cl1,cl2,cl3;
int cmp1(node x,node y){
	return x.fi>y.fi; 
}
int cmp2(node x,node y){
	return x.se>y.se; 
}
int cmp3(node x,node y){
	return x.th>y.th; 
}
long long cnt=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cl1=0,cl2=0,cl3=0;
		cnt=0;
		for(int i=0;i<n;i++){
			stu[i].vis=0;
			cin>>stu[i].fi>>stu[i].se>>stu[i].th;
//			cout<<stu[i].fi<<" "<<stu[i].se<<" "<<stu[i].th<<endl;
			if(stu[i].fi>=stu[i].se and stu[i].fi>=stu[i].th){
				stu[i].maxm=1;	
			}else if(stu[i].se>=stu[i].fi and stu[i].se>=stu[i].th){
				stu[i].maxm=2;
			}else if(stu[i].th>=stu[i].fi and stu[i].th>=stu[i].se){
				stu[i].maxm=3;
			}
//			cout<<stu[i].maxm<<"+++++"<<endl;
		}
		maxc=n/2;//最多招几个人 
		
		
		//先分走自愿的 
		sort(stu,stu+n,cmp1);
		for(int i=0;i<n;i++){
			if(stu[i].maxm==1 and cl1<maxc and stu[i].vis==0){
				cnt+=stu[i].fi;
//				cout<<stu[i].fi<<endl;
				cl1++;
				stu[i].vis=1;
			}
			if(cl1>=maxc){
				break;
			}
		}
//		for(int i=0;i<n;i++){
//			cout<<stu[i].fi<<"%%% "<<stu[i].se<<" "<<stu[i].th<<endl;
//		}	
//		cout<<endl;
		sort(stu,stu+n,cmp2);
		for(int i=0;i<n;i++){
			if(stu[i].maxm==2 and cl2<maxc and stu[i].vis==0){
				cnt+=stu[i].se;
//				cout<<stu[i].se<<endl;
				cl2++;
				stu[i].vis=1;
			}
			if(cl2>=maxc){
				break;
			}
		}
//		for(int i=0;i<n;i++){
//			cout<<stu[i].fi<<"$$$ "<<stu[i].se<<" "<<stu[i].th<<endl;
//		}
//		cout<<endl;
		sort(stu,stu+n,cmp3);
		for(int i=0;i<n;i++){
			if(stu[i].maxm==3 and cl3<maxc and stu[i].vis==0){
				cnt+=stu[i].th;
//				cout<<stu[i].th<<endl;
				cl3++;
				stu[i].vis=1;
			}
			if(cl3>=maxc){
				break;
			}
		}
//		for(int i=0;i<n;i++){
//			cout<<stu[i].fi<<"### "<<stu[i].se<<" "<<stu[i].th<<endl;
//		}
//		cout<<endl;
		
		
		//再分不自愿的 
		for(int i=0;i<n;i++){
			if(stu[i].vis==0){
				if(stu[i].maxm==1){//满意第1个 
					int cha;
					if(stu[i].se >= stu[i].th and cl2<maxc){
						cha=stu[i].fi-stu[i].se;
						cnt+=stu[i].se;
						cl2++;
						stu[i].vis=1;
					}else if(stu[i].th >= stu[i].se and cl3<maxc){
						cha=stu[i].fi-stu[i].th;
						cnt+=stu[i].th;
						cl3++;
						stu[i].vis=1;
					}
				}else if(stu[i].maxm==2){//满意第2个
					int cha; 
					if(stu[i].fi >= stu[i].th and cl1<maxc){
						cha=stu[i].se-stu[i].fi;
						cnt+=stu[i].fi;
						cl1++;
						stu[i].vis=1;
					}else if(stu[i].th >= stu[i].fi and cl3<maxc){
						cha=stu[i].se-stu[i].th;
						cnt+=stu[i].th;
						cl3++;
						stu[i].vis=1;
					}
				}else{//满意第3个
					int cha; 
					if(stu[i].fi >= stu[i].se and cl1<maxc){
						cha=stu[i].th-stu[i].fi;
						cnt+=stu[i].fi;
						cl1++;
						stu[i].vis=1;
					}else if(stu[i].se >= stu[i].fi and cl2<maxc){
						cha=stu[i].th-stu[i].se;
						cnt+=stu[i].se;
						cl2++;
						stu[i].vis=1;
					}
				}
			}
		}
//		cout<<"cl:"<<cl1<<"  "<<cl2<<"  "<<cl3<<"  "<<endl;
		cout<<cnt<<endl;	
	} 
	return 0;
}
