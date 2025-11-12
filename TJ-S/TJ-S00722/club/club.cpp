#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
/*
_________________________________________________
					  |
					__v_
				   /x x \
				   | ^  |
				   \____/
				      |
				     /|\
					  |
					  /\
					 /  \
					  
*/ 
struct stu{
	int id;
	int myd;
};
struct qry{
	stu x[5];
	bool chosen=false;
	int mx=-1;
	int mxl=-1;
};
int T;
int n;
int line;

bool cmpline(qry m,qry n){
    if(m.chosen) return false;
    if(n.chosen) return true;
    if(m.mxl==line && n.mxl==line){
        int summ=0,sumn=0;
        for(int q=1;q<=3;q++){
            if(q<=line) continue;
            summ+=m.x[q].myd;
            sumn+=n.x[q].myd;
        }
        return summ<=sumn;
    }
    else{
        if(m.mxl==line){
            return true;
        }
        if(n.mxl==line){
            return false;
        }
    }

    return m.x[line].myd>n.x[line].myd;
}
bool cmplast(stu x,stu y){
    return x.myd>y.myd;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int b[15]={0,0,0,0};
		qry a[100005];
		ll ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x[1].myd>>a[i].x[2].myd>>a[i].x[3].myd;
			a[i].x[1].id=1;a[i].x[2].id=2;a[i].x[3].id=3;
			a[i].mx=max(a[i].x[1].myd,max(a[i].x[2].myd,a[i].x[3].myd));
			if(a[i].mx==a[i].x[1].myd){
				a[i].mxl=1;
			}
			else if(a[i].mx==a[i].x[2].myd){
				a[i].mxl=2;
			}
			else if(a[i].mx==a[i].x[3].myd){
				a[i].mxl=3;
			}
		}
		for(int l=1;l<=3;l++){
            line=l;
            sort(a+1,a+1+n,cmpline);

            int i=1;
            while(b[l]+1<=n/2 && i<=n){
                if(i>n)break;
                if(!a[i].chosen){

                    if(l==2){
                        a[i].mx=max(a[i].x[2].myd,a[i].x[3].myd);
                    }
                    if(l==3){
                        a[i].mx=a[i].x[3].myd;
                    }
                    if(a[i].mx==a[i].x[l].myd){
                        b[l]++;
                        ans+=a[i].x[l].myd;
                        a[i].chosen=true;
                        //cout<<a[i].x[l].myd<<endl;
                    }
                }
                i++;
            }
		}

		for(int i=1;i<=n;i++){
            if(!a[i].chosen){
                sort(a[i].x+1,a[i].x+4,cmplast);
                for(int j=1;j<=3;j++){
                    int id=a[i].x[j].id;
                    if(b[id]+1<=n/2){
                        ans+=a[i].x[j].myd;
                        //cout<<id<<" "<<a[i].x[j].myd<<" "<<b[id]<<endl;
                        //cout<<a[i].x[j].myd<<endl;
                        b[id]++;
                        break;
                    }
                }
            }
		}

		cout<<ans<<endl;
	}
	return 0;
}
