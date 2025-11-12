#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,na,nb,nc;
struct stu{
    int a,b,c;//,id;
    char nw;
}f[200005];
int sum;
vector <int> a,b,c;
/*bool ts(stu a,stu b){
    a.id < b.id;
}*/
bool cmpa(stu a,stu b){
    /*if (a.a != b.a){
        return a.a < b.a;
    }
    return */
    if (a.nw != b.nw){
        if (a.nw == 'a'){
            return true;
        }else if(b.nw == 'a'){
            return false;
        }
    }
    int ma=max(a.b,a.c),mb=max(b.b,b.c);
    return ma-a.a > mb-b.a;
}
bool cmpb(stu a,stu b){
    /*if (a.a != b.a){
        return a.a < b.a;
    }
    return */
    if (a.nw != b.nw){
        if (a.nw == 'b'){
            return true;
        }else if(b.nw == 'b'){
            return false;
        }
    }
    int ma=max(a.a,a.c),mb=max(b.a,b.c);
    return ma-a.b > mb-b.b;
}
bool cmpc(stu a,stu b){
    /*if (a.a != b.a){
        return a.a < b.a;
    }
    return */
    if (a.nw != b.nw){
        if (a.nw == 'c'){
            return true;
        }else if(b.nw == 'c'){
            return false;
        }
    }
    int ma=max(a.b,a.a),mb=max(b.b,b.a);
    return ma-a.c > mb-b.c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin >> t;
    while (t--){
        sum = 0;
        cin >> n;
        na=0;
        nb=0;
        nc=0;
        for (int i=1;i<=n;i++){
            cin >> f[i].a >> f[i].b >> f[i].c;
            f[i].id = i;
            if (f[i].a >= f[i].b && f[i].a >= f[i].c){
                na++;
                //a.push_back(i);
                f[i].nw = 'a';
                sum += f[i].a;
            }else if(f[i].b >= f[i].c){
                nb++;
                //b.push_back(i);
                f[i].nw = 'b';
                sum += f[i].b;
            }else{
                nc++;
                //c.push_back(i);
                f[i].nw = 'c';
                sum += f[i].c;
            }
        }
        if (na > n/2){
            sort(f+1,f+n+1,cmpa);
            int now=na-n/2;
            for (int i=1;i<=now;i++){
                na--;
                sum -= f[i].a;
                if (f[i].b > f[i].c){
                    nb++;
                    f[i].nw = 'b';
                    sum += f[i].b;
                }else if(f[i].b < f[i].c){
                    nc++;
                    f[i].nw = 'c';
                    sum += f[i].c;
                }else{
                    if (nb < nc){
                        nb++;
                        f[i].nw = 'b';
                        sum += f[i].b;
                    }else{
                        nc++;
                        f[i].nw = 'c';
                        sum += f[i].c;
                    }
                }
            }
        }
        if (nb > n/2){
            sort(f+1,f+n+1,cmpb);
            int now = nb-n/2;
            for (int i=1;i<=now;i++){
                nb--;
                sum -= f[i].b;
                if (f[i].a > f[i].c){
                    //cout << 'a' << endl;
                    na++;
                    f[i].nw = 'a';
                    sum += f[i].a;
                }else if(f[i].a < f[i].c){
                    //cout << 'c' << endl;
                    nc++;
                    f[i].nw = 'c';
                    sum += f[i].c;
                }else{
                    if (na < nc){
                        //cout << 'a' << endl;
                        na++;
                        f[i].nw = 'a';
                        sum += f[i].a;
                    }else{
                        //cout << 'c' << endl;
                        nc++;
                        f[i].nw = 'c';
                        sum += f[i].c;
                    }
                }
            }
        }
        if (nc > n/2){
            sort(f+1,f+n+1,cmpc);
            int now = nc-n/2;
            for (int i=1;i<=now;i++){
                nc--;
                sum -= f[i].c;
                if (f[i].b > f[i].a){
                    nb++;
                    f[i].nw = 'b';
                    sum += f[i].b;
                }else if(f[i].b < f[i].a){
                    na++;
                    f[i].nw = 'a';
                    sum += f[i].a;
                }else{
                    if (nb < na){
                        nb++;
                        f[i].nw = 'b';
                        sum += f[i].b;
                    }else{
                        na++;
                        f[i].nw = 'a';
                        sum += f[i].a;
                    }
                }
            }
        }
        /*sort(f+1,f+n+1,ts);
        for (int i=1;i<=n;i++){
            cout << f[i].nw << " ";
        }
        printf("\n%d %d %d\n",na,nb,nc);
        /*for (int i=0;i<a.size();i++){
            sum += f[a[i]].a;
        }
        for (int i=0;i<b.size();i++){
            sum += f[b[i]].b;
        }
        for (int i=0;i<c.size();i++){
            sum += f[c[i]].c;
        }*/
        cout << sum << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
