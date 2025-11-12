#include<bits/stdc++.h>
using namespace std;
struct stu{
	int l1;
	int l2;
	int l3;
	int lm;
	int c1=0;
	int c2=0;
	int c3=0;
};
queue<stu> a;
int mn;
stu c[50005][3];
int ins(stu stm,int n){
	if(c[0][n].lm==0){
		c[0][n]=stm;
		return 1;//成功 
	}
	int i=0;
	while(stm.lm<=c[i][n].lm){
		i++;
	}
	if(i>=mn && c[i][n].lm>=stm.lm){
		return 0;//不加入 
	}
	int j=i;
	stu tmp=c[j][n];
	for(j;c[j][n].lm!=0;j++){
		tmp=c[j][n];
		c[j][n]=stm;
		stm=tmp;	
	}
	c[j][n]=tmp;
//	clog<<"j="<<j;
//	for(int i1=0;i1<=j;i1++){
//		clog<<c[i1][n].lm<<" ";
//	}
	if(j>=mn){
		return 2;//有被退出的 
	}
	return 1;
}


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
	while(T--){
		memset(c,0,sizeof(c));
	    int n1;
	    cin>>n1;
	    mn=n1/2;
//	    clog<<"mn="<<mn<<endl;
	    for(int i=0;i<n1;i++){
	    	stu stu1;
			cin>>stu1.l1;
			cin>>stu1.l2;
			cin>>stu1.l3;
			a.push(stu1);
		}
		while(!a.empty()){
			stu stu1=a.front();
			a.pop();
			int b1=-1,b2=-1,b3=-1;
			if(stu1.c1==0)b1=stu1.l1;
			if(stu1.c2==0)b2=stu1.l2;
			if(stu1.c3==0)b3=stu1.l3;
//			clog<<"b="<<b1<<" "<<b2<<" "<<b3<<" "<<endl;
//			if(b1>b2){
//				if(b1>b3){
//					stu1.lm=b1;
//				}else{
//					stu1.lm=b3;
//				}
//			}else{
//				if(b2>b3){
//					stu1.lm=b2;
//				}else{
//					stu1.lm=b3;
//				}
//			}
//			
//			stu1.lm=stu1.lm>b3?stu1.lm:b3;
			stu1.lm=max(max(b1,b2),b3);
			int n=-1;
			if(stu1.lm==stu1.l1){
				n=0;
			}else if(stu1.lm==stu1.l2){
				n=1;
			}else if(stu1.lm==stu1.l3){
				n=2;
			}
//			clog<<stu1.l1<<" "<<stu1.l2<<" "<<stu1.l3<<" "<<stu1.c1<<" "<<stu1.c2<<" "<<stu1.c3<<" "<<stu1.lm;
//			clog<<"n="<<n<<endl;
			int ins_code=ins(stu1,n);
//			clog<<"code="<<ins_code<<"\ndata: \n";
			if(ins_code==0){
				if(n==0){
					stu1.c1=-1;
				}else if(n==1){
					stu1.c2=-1;
				}else if(n==2){
					stu1.c3=-1; 
				}
				a.push(stu1);
			}else if(ins_code==2){
				stu1=c[mn][n];
				if(n==0){
					stu1.c1=-1;
				}else if(n==1){
					stu1.c2=-1;
				}else if(n==2){
					stu1.c3=-1; 
				}
				a.push(stu1);
//				clog<<"c[mn][n]:"<<stu1.l1<<" "<<stu1.l2<<" "<<stu1.l3<<" "<<stu1.c1<<" "<<stu1.c2<<" "<<stu1.c3<<" "<<stu1.lm;
				c[mn][n].lm=0;
			}
//			if(a.empty()){
//				clog<<"empty"<<endl;
//				break;
//			}
		}
		long long ans=0;
		for(int i=0;i<n1;i++){
			for(int j=0;j<3;j++){
//				printf("c[%d][%d]=%d\n",i,j,c[i][j].lm);
				ans+=c[i][j].lm;
			}
		}
		cout<<ans<<endl;
			
    }
   
   
    return 0; 
}
