#include<bits/stdc++.h>
using namespace std;
int jk(int e,int s){
    return e>s;
}
long long zong=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--){
        zong=0;
        cin>>n;
        int l[3],d=n/2,a[d],b[d],c[d],ad=-1,bd=-1,cd=-1;
        for(int i=0;i<n;i++){
            cin>>l[0]>>l[1]>>l[2];
            if(l[0]>l[1]&&l[0]>l[2]){
                if(ad<d){
                    ad++;
                    a[ad]=l[0];
                    sort(a,a+ad,jk);
                }
                else if(ad>d){
                    if(l[0]>a[ad]){
                        a[ad]=l[0];
                    }
                }
	            else{
	                if(l[1]>l[2]){
		                if(bd<d){
		                    bd++;
		                    b[bd]=l[1];
		                    sort(b,b+bd,jk);
		                }
		                else{
		                    if(l[1]>b[bd]){
		                        b[bd]=l[1];
		                    }
		                }
		            }
		            else if(l[2]>l[1] ){
		                if(cd<d){
		                    cd++;
		                    c[cd]=l[2];
		                    sort(c,c+cd,jk);
		                }
		                else{
		                    if(l[2]>c[cd]){
		                        c[cd]=l[2];
		                    }
		                }
		            }
				}
            }
            else if(l[1]>l[0] && l[1]>l[2]){
                if(bd<d){
                    bd++;
                    b[bd]=l[1];
                    sort(b,b+bd,jk);
                }
                else{
                    if(l[1]>b[bd]){
                        b[bd]=l[1];
                    }
                }
            }
            else if(l[2]>l[1] && l[0]<l[2]){
                if(cd<d){
                    cd++;
                    c[cd]=l[2];
                    sort(c,c+cd,jk);
                }
                else{
                    if(l[2]>c[cd]){
                        c[cd]=l[2];
                    }
                }
            }
            else if(l[0]==l[1] && l[0]==l[2]){
                if(ad<bd && ad<d && ad<cd){
                    ad++;
                    a[ad]=l[0];
                    sort(a,a+ad,jk);
                }
                else if(bd<d && bd<cd &&ad>bd){
                    bd++;
                    b[bd]=l[1];
                    sort(b,b+bd,jk);
                }
                else if(cd<bd && cd<d && cd<ad){
                    cd++;
                    c[cd]=l[2];
                    sort(c,c+cd,jk);
                }
                else{
                    if(l[1]>b[bd]){
                        b[bd]=l[1];
                    }
                    else if(l[0]>a[ad]){
                        a[ad]=l[0];
                    }
                    else if(l[2]>c[cd]){
                        c[cd]=l[2];
                    }
                }
            }
            else if(l[0]==l[1] && l[0]>l[2]){
                if(ad<bd && ad<d){
                    ad++;
                    a[ad]=l[0];
                    sort(a,a+ad,jk);
                }
                else if(bd<d){
                    bd++;
                    b[bd]=l[1];
                    sort(b,b+bd,jk);
                }
                else{
                    if(l[1]>b[bd]){
                        b[bd]=l[1];
                    }
                    else if(l[0]>a[ad]){
                        a[ad]=l[0];
                    }
                }
            }
            else{
                if(cd<bd && cd<d){
                    cd++;
                    c[cd]=l[2];
                    sort(c,c+cd,jk);
                }
                else if(bd<d){
                    bd++;
                    b[bd]=l[1];
                    sort(b,b+bd,jk);
                }
                else{
                    if(l[1]>b[bd]){
                        b[bd]=l[1];
                    }
                    else if(l[2]>c[cd]){
                        c[cd]=l[2];
                    }
                }
            }
        }
        for(int i=0;i<=ad;i++){
        	zong+=a[i];
		}
		for(int i=0;i<=bd;i++){
        	zong+=b[i];
		}
		for(int i=0;i<=cd;i++){
        	zong+=c[i];
		}
		cout<<zong<<endl;
    }
    return 0;
}
