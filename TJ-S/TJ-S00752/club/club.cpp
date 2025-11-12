#include<bits/stdc++.h>
using namespace std;

struct a{

    int a,b,c;
    int m1,m2,m3;

    bool ask=0;

};

bool acmp(a x,a y){

    return x.a>y.a;

}
bool bcmp(a x,a y){

    return x.b>y.b;

}
bool ccmp(a x,a y){

    return x.c>y.c;

}

bool cmp(int a,int b){
	
	return a>b;
	
}

int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin >> t;
    int ans[t],p=0;
    while(t){

        int n;
        cin >>n;

        a x[6];
        for(int i=0;i<n;i++){
            cin >>x[i].a >>x[i].b >>x[i].c;
            if(x[i].a>x[i].b &&x[i].a>x[i].c){
                if(x[i].b>x[i].c){
                    x[i].m1=x[i].a;
                    x[i].m2=x[i].b;
                    x[i].m3=x[i].c;
                }else if(x[i].b<x[i].c){
                    x[i].m1=x[i].a;
                    x[i].m2=x[i].c;
                    x[i].m3=x[i].b;
                }
            }
            if(x[i].b>x[i].a &&x[i].b>x[i].c){
                if(x[i].a>x[i].c){
                    x[i].m1=x[i].b;
                    x[i].m2=x[i].a;
                    x[i].m3=x[i].c;
                }else if(x[i].a<x[i].c){
                    x[i].m1=x[i].b;
                    x[i].m2=x[i].c;
                    x[i].m3=x[i].a;
                }
            }
            if(x[i].c>x[i].b &&x[i].c>x[i].a){
                if(x[i].b>x[i].a){
                    x[i].m1=x[i].c;
                    x[i].m2=x[i].b;
                    x[i].m3=x[i].a;
                }else if(x[i].b<x[i].a){
                    x[i].m1=x[i].c;
                    x[i].m2=x[i].a;
                    x[i].m3=x[i].b;
                }
            }
        }

        int c1=0,c2=0,c3=0;
        int cnt1=0,cnt2=0,cnt3=0;
        int h=n/2;
		
		int mcnt=0;
		
		//1
		sort(x,x+n,acmp);
		
        for(int i=0;i<n;i++){
            if(x[i].m1==x[i].a){
                if(c1+1<=h && x[i].ask==0){
                    c1++;
                    cnt1+=x[i].a;
                    x[i].ask=1;
                }else if(x[i].m2==x[i].b){
                    if(c2+1<=h && x[i].ask==0){
                        c2++;
                        cnt1+=x[i].b;
                        x[i].ask=1;
                    }else if(c3+1<=h && x[i].ask==0){
                        c3++;
                        cnt1+=x[i].c;
                        x[i].ask=1;
                    }
                }else if(x[i].m2==x[i].c){
                    if(c3+1<=h && x[i].ask==0){
                        c3++;
                        cnt1+=x[i].c;
                        x[i].ask=1;
                    }else if(c2+1<=h && x[i].ask==0){
                        c2++;
                        cnt1+=x[i].b;
                        x[i].ask=1;
                    }
                }
            }else if(x[i].m1==x[i].b){
                if(c2+1<=h && x[i].ask==0){
                    c2++;
                    cnt1+=x[i].b;
                    x[i].ask=1;
                }else if(x[i].m2==x[i].a){
                    if(c1+1<=h && x[i].ask==0){
                        c1++;
                        cnt1+=x[i].a;
                        x[i].ask=1;
                    }else if(c3+1<=h && x[i].ask==0){
                        c3++;
                        cnt1+=x[i].c;
                        x[i].ask=1;
                    }
                }else if(x[i].m2==x[i].c){
                    if(c3+1<=h && x[i].ask==0){
                        c3++;
                        cnt1+=x[i].c;
                        x[i].ask=1;
                    }else if(c1+1<=h && x[i].ask==0){
                        c1++;
                        cnt1+=x[i].a;
                        x[i].ask=1;
                    }
                }
            }else if(x[i].m1==x[i].c){
                if(c3+1<=h && x[i].ask==0){
                    c3++;
                    cnt1+=x[i].c;
                    x[i].ask=1;
                }else if(x[i].m2==x[i].b){
                    if(c2+1<=h && x[i].ask==0){
                        c2++;
                        cnt1+=x[i].b;
                        x[i].ask=1;
                    }else if(c1+1<=h && x[i].ask==0){
                        c1++;
                        cnt1+=x[i].a;
                        x[i].ask=1;
                    }
                }else if(x[i].m2==x[i].a){
                    if(c1+1<=h && x[i].ask==0){
                        c1++;
                        cnt1+=x[i].a;
                        x[i].ask=1;
                    }else if(c2+1<=h && x[i].ask==0){
                        c2++;
                        cnt1+=x[i].b;
                        x[i].ask=1;
                    }
                }
            }
        }
        
        //2
        c1=0,c2=0,c3=0;
		sort(x,x+n,bcmp);
		for(int i=0;i<n;i++){
			x[i].ask=0;
		}
		
		
        for(int i=0;i<n;i++){
            if(x[i].m1==x[i].a){
                if(c1+1<=h && x[i].ask==0){
                    c1++;
                    cnt2+=x[i].a;
                    x[i].ask=1;
                }else if(x[i].m2==x[i].b){
                    if(c2+1<=h && x[i].ask==0){
                        c2++;
                        cnt2+=x[i].b;
                        x[i].ask=1;
                    }else if(c3+1<=h && x[i].ask==0){
                        c3++;
                        cnt2+=x[i].c;
                        x[i].ask=1;
                    }
                }else if(x[i].m2==x[i].c){
                    if(c3+1<=h && x[i].ask==0){
                        c3++;
                        cnt2=x[i].c;
                        x[i].ask=1;
                    }else if(c2+1<=h && x[i].ask==0){
                        c2++;
                        cnt2+=x[i].b;
                        x[i].ask=1;
                    }
                }
            }else if(x[i].m1==x[i].b){
                if(c2+1<=h && x[i].ask==0){
                    c2++;
                    cnt2+=x[i].b;
                    x[i].ask=1;
                }else if(x[i].m2==x[i].a){
                    if(c1+1<=h && x[i].ask==0){
                        c1++;
                        cnt2+=x[i].a;
                        x[i].ask=1;
                    }else if(c3+1<=h && x[i].ask==0){
                        c3++;
                        cnt2+=x[i].c;
                        x[i].ask=1;
                    }
                }else if(x[i].m2==x[i].c){
                    if(c3+1<=h && x[i].ask==0){
                        c3++;
                        cnt2+=x[i].c;
                        x[i].ask=1;
                    }else if(c1+1<=h && x[i].ask==0){
                        c1++;
                        cnt2+=x[i].a;
                        x[i].ask=1;
                    }
                }
            }else if(x[i].m1==x[i].c){
                if(c3+1<=h && x[i].ask==0){
                    c3++;
                    cnt2+=x[i].c;
                    x[i].ask=1;
                }else if(x[i].m2==x[i].b){
                    if(c2+1<=h && x[i].ask==0){
                        c2++;
                        cnt2+=x[i].b;
                        x[i].ask=1;
                    }else if(c1+1<=h && x[i].ask==0){
                        c1++;
                        cnt2+=x[i].a;
                        x[i].ask=1;
                    }
                }else if(x[i].m2==x[i].a){
                    if(c1+1<=h && x[i].ask==0){
                        c1++;
                        cnt2+=x[i].a;
                        x[i].ask=1;
                    }else if(c2+1<=h && x[i].ask==0){
                        c2++;
                        cnt2+=x[i].b;
                        x[i].ask=1;
                    }
                }
            }
        }
        
        
        //3
        c1=0,c2=0,c3=0;
		sort(x,x+n,ccmp);
		for(int i=0;i<n;i++){
			x[i].ask=0;
		}
		
        for(int i=0;i<n;i++){
            if(x[i].m1==x[i].a){
                if(c1+1<=h && x[i].ask==0){
                    c1++;
                    cnt3+=x[i].a;
                    x[i].ask=1;
                }else if(x[i].m2==x[i].b){
                    if(c2+1<=h && x[i].ask==0){
                        c2++;
                        cnt3+=x[i].b;
                        x[i].ask=1;
                    }else if(c3+1<=h && x[i].ask==0){
                        c3++;
                        cnt3+=x[i].c;
                        x[i].ask=1;
                    }
                }else if(x[i].m2==x[i].c){
                    if(c3+1<=h && x[i].ask==0){
                        c3++;
                        cnt3=x[i].c;
                        x[i].ask=1;
                    }else if(c2+1<=h && x[i].ask==0){
                        c2++;
                        cnt3+=x[i].b;
                        x[i].ask=1;
                    }
                }
            }else if(x[i].m1==x[i].b){
                if(c2+1<=h && x[i].ask==0){
                    c2++;
                    cnt3+=x[i].b;
                    x[i].ask=1;
                }else if(x[i].m2==x[i].a){
                    if(c1+1<=h && x[i].ask==0){
                        c1++;
                        cnt3+=x[i].a;
                        x[i].ask=1;
                    }else if(c3+1<=h && x[i].ask==0){
                        c3++;
                        cnt3+=x[i].c;
                        x[i].ask=1;
                    }
                }else if(x[i].m2==x[i].c){
                    if(c3+1<=h && x[i].ask==0){
                        c3++;
                        cnt3+=x[i].c;
                        x[i].ask=1;
                    }else if(c1+1<=h && x[i].ask==0){
                        c1++;
                        cnt3+=x[i].a;
                        x[i].ask=1;
                    }
                }
            }else if(x[i].m1==x[i].c){
                if(c3+1<=h && x[i].ask==0){
                    c3++;
                    cnt3+=x[i].c;
                    x[i].ask=1;
                }else if(x[i].m2==x[i].b){
                    if(c2+1<=h && x[i].ask==0){
                        c2++;
                        cnt3+=x[i].b;
                        x[i].ask=1;
                    }else if(c1+1<=h && x[i].ask==0){
                        c1++;
                        cnt3+=x[i].a;
                        x[i].ask=1;
                    }
                }else if(x[i].m2==x[i].a){
                    if(c1+1<=h && x[i].ask==0){
                        c1++;
                        cnt3+=x[i].a;
                        x[i].ask=1;
                    }else if(c2+1<=h && x[i].ask==0){
                        c2++;
                        cnt3+=x[i].b;
                        x[i].ask=1;
                    }
                }
            }
        }
        
        //4
        int cnt4=0;
        c1=0,c2=0,c3=0;
		for(int i=0;i<n;i++){
			x[i].ask=0;
		}
		sort(x,x+n,acmp);
		
		for(int i=0;i<n;i++){
			if(c1+1<=h && x[i].ask==0){
				c1++;
				cnt4+=x[i].a;
				x[i].ask=1;
			}
		}
		
		sort(x,x+n,bcmp);
		
		for(int i=0;i<n;i++){
			if(c2+1<=h && x[i].ask==0){
				c2++;
				cnt4+=x[i].b;
				x[i].ask=1;
			}
		}
		
		sort(x,x+n,ccmp);
		
		for(int i=0;i<n;i++){
			if(c3+1<=h && x[i].ask==0){
				c3++;
				cnt4+=x[i].c;
				x[i].ask=1;
			}
		}
		//5
		
		int cnt5=0;
		int oo[n];
		for(int i=0;i<n;i++){
			oo[i]=x[i].m1;
		}
		sort(oo,oo+n,cmp);
		for(int i=0;i<h;i++){
			cnt5+=oo[i];
		}
		
        int u[5]={0};
        u[0]=cnt1;
        u[1]=cnt2;
        u[2]=cnt3;
        u[3]=cnt4;
        //u[4]=cnt5;
        sort(u,u+5,cmp);
        mcnt=u[0];
        ans[p]=mcnt;
        t--;
        p++;
    }

    for(int i=0;i<p;i++){
    	cout << ans[i] << endl;
	}

    return 0;

}
