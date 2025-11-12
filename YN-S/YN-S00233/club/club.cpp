#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
LL z;
cin>>z;
vector<LL> kx(z,0);
for(LL d=0;d<z;d++){
LL n,my=0,sh=0,on=0,tw=0,th=0,oldon=0,oldone=0,oldtw=0,oldtwo=0,oldth=0,oldthr=0;
cin>>n;
for(LL i=0;i<n;i++){
        bool aa=false,bb=false,cc=false;
   for(LL j=0;j<3;j++){
    LL p=0;
   cin>>p;
    sh=j;
if(sh==0&&aa!=true&&bb!=true){
 if(th<n/2){
 if(p>oldth&&p<oldthr){
 my=my-oldth+p;
 }else if(p>oldth&&p>oldthr){
 if(oldth>=oldthr){
 my=my-oldthr+p;
 }else{
 my=my-oldth+p;
 }
 }else{
 my=my-oldthr+p;
 }
 sh=0;
}
cc=true;
}else if(sh==1&&cc!=true&&bb!=true){
if(on<n/2){
 if(p>oldon&&p<oldone){
 my=my-oldon+p;
 }else if(p>oldon&&p>oldone){
 if(oldon>=oldone){
 my=my-oldone+p;
 }else{
 my=my-oldon+p;
 }
 }else{
 my=my-oldone+p;
 }
 sh=1;
}
aa=true;
}else if(sh==2&&aa!=true&&cc!=true){
if(tw<n/2){
 if(p>oldtw&&p<oldtwo){
 my=my-oldtw+p;
 }else if(p>oldtw&&p>oldtwo){
 if(oldtw>=oldtwo){
 my=my-oldtwo+p;
 }else{
 my=my-oldtw+p;
 }
 }else{
 my=my-oldtwo+p;
 }
 sh=2;
}
bb=true;
 }else if(sh==0&&aa!=true){
 if(th<n/2){
 if(p>oldth&&p<oldthr){
 my=my-oldth+p;
 }else if(p>oldth&&p>oldthr){
 if(oldth>=oldthr){
 my=my-oldthr+p;
 }else{
 my=my-oldth+p;
 }
 }else{
 my=my-oldthr+p;
 }
 sh=0;
}
cc=true;
}else if(sh==1&&cc!=true){
if(on<n/2){
 if(p>oldon&&p<oldone){
 my=my-oldon+p;
 }else if(p>oldon&&p>oldone){
 if(oldon>=oldone){
 my=my-oldone+p;
 }else{
 my=my-oldon+p;
 }
 }else{
 my=my-oldone+p;
 }
 sh=1;
}
aa=true;
}else if(sh==2&&aa!=true){
if(tw<n/2){
 if(p>oldtw&&p<oldtwo){
 my=my-oldtw+p;
 }else if(p>oldtw&&p>oldtwo){
 if(oldtw>=oldtwo){
 my=my-oldtwo+p;
 }else{
 my=my-oldtw+p;
 }
 }else{
 my=my-oldtwo+p;
 }
 sh=2;
}
bb=true;
 }else if(sh==0&&bb!=true){
 if(th<n/2){
 if(p>oldth&&p<oldthr){
 my=my-oldth+p;
 }else if(p>oldth&&p>oldthr){
 if(oldth>=oldthr){
 my=my-oldthr+p;
 }else{
 my=my-oldth+p;
 }
 }else{
 my=my-oldthr+p;
 }
 sh=0;
}
cc=true;
}else if(sh==1&&bb!=true){
if(on<n/2){
 if(p>oldon&&p<oldone){
 my=my-oldon+p;
 }else if(p>oldon&&p>oldone){
 if(oldon>=oldone){
 my=my-oldone+p;
 }else{
 my=my-oldon+p;
 }
 }else{
 my=my-oldone+p;
 }
 sh=1;
}
aa=true;
}else if(sh==2&&cc!=true){
if(tw<n/2){
 if(p>oldtw&&p<oldtwo){
 my=my-oldtw+p;
 }else if(p>oldtw&&p>oldtwo){
 if(oldtw>=oldtwo){
 my=my-oldtwo+p;
 }else{
 my=my-oldtw+p;
 }
 }else{
 my=my-oldtwo+p;
 }
 sh=2;
}
bb=true;
 }


if(j==0){
    oldone=oldon;
    oldon=p;
    }else if(j==1){
    oldtwo=oldtw;
    oldtw=p;
    }else if(j==2){
    oldthr=oldth;
    oldth=p;
    }


}
if(sh==0){
    th+=1;
 }else if(sh==1){
 on+=1;
 }else if(sh==2){
 tw+=1;
 }
}
kx[d]=my;
}
for(LL i=0;i<z;i++){
  cout<<kx[i]<<endl;
}


return 0;
}
