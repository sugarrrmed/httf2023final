#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<atcoder/all>
#include<bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
//typedef int ll;

/*
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
namespace multi = boost::multiprecision;
typedef multi::cpp_int LL;
typedef multi::number<multi::cpp_dec_float<1024>> DD;// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
//*/
typedef long double dd;
typedef pair<ll,ll> l_l;
typedef pair<dd,dd> d_d;
ll inf=(ll)1E18;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define rrep(i,r,l) for(ll i=r;i>=l;i--)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
dd EPS=1E-12;
#define fi first
#define se second

#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
template<class T,class S>
inline bool chmax(T &a, S b) {
    if(a < b) {
        a = (T)b;
        return true;
    }
    return false;
}
template<class T,class S>
inline bool chmin(T &a, S b) {
    if(a > b) {
        a = (T)b;
        return true;
    }
    return false;
}
#define all(c) c.begin(),c.end()

//using mint = modint998244353;
//using mint = modint1000000007;
//using mint=modint;
//using mint=static_modint<100>;
//using mint=dd;
//using mint=ll;

typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl>vvvl;
typedef vector<vvvl>vvvvl;
/*
typedef vector<mint>vi;
typedef vector<vi>vvi;
typedef vector<vvi>vvvi;
typedef vector<vvvi>vvvvi;
typedef pair<mint,mint>i_i;
typedef vector<i_i>vi_i;
 //*/
typedef vector<l_l>vl_l;
typedef vector<vl_l>vvl_l;
typedef vector<string>vs;
typedef vector<vs>vvs;
typedef vector<dd> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<d_d>vd_d;
dd PI=acos((dd)-1);

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); cout<<setprecision(20);
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

//#define endl "\n"  //インタラクティブで消す！！！！！！！！！！！！！！！！！！！！！
#define popcount __builtin_popcountll
#define SHUFFLE(v) shuffle(all(v),default_random_engine(chrono::system_clock::now().time_since_epoch().count()))
//////////////////////////////////////////////////////////////////////////////
template<class S>
void DEBUG_PRINT(S x){
    cerr<<x<<endl;
}
template<class S,class T>
void DEBUG_PRINT(pair<S,T>x){
    cerr<<"("<<x.fi<<","<<x.se<<")"<<endl;
}
template<class S>
void DEBUG_PRINT(vector<S> x){
    for(auto y:x)cerr<<setw(2)<<y<<" ";
    cerr<<endl;
}
template<class S,class T>
void DEBUG_PRINT(vector<pair<S,T>>x){
    for(auto y:x)cerr<<"("<<y.fi<<","<<y.se<<") ";
    cerr<<endl;
}
template<class S>
void DEBUG_PRINT(vector<vector<S>> x){
    cerr<<endl;
    for(auto y:x){
        for(auto z:y){
            cerr<<setw(2)<<z<<" ";
        }cerr<<endl;
    }cerr<<endl;
}

#define TO_STRING_FOR_DEBUG(VariableName) # VariableName
#ifdef LOCAL
#define DEB(V) cerr<< TO_STRING_FOR_DEBUG(V) << ": "; DEBUG_PRINT(V);
#else
#define DEB(V) void(0)
#endif

#define importantBit(x) (63-__builtin_clzll(x))
/////////////////////////////////////////////////////////////////////////////////////////
unsigned int randxor(){
    //0 以上 (2^32)-1 以下の整数(だと思う)
    static unsigned int x=123456789,y=362436069,z=521288629,w=88675123;
    unsigned int t;
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}
ll rand(ll a,ll b){
    //a以上b以下の整数を返す。
    assert(a<=b);
    ll len=(b-a+1);
    return randxor()%len + a;
}
dd randdouble(dd l,dd r){
    //l以上r以下の実数を返す。
    assert(l<=r + EPS);
    return l + (r-l) * (dd)randxor()/4294967295;
}
struct timespec START_TIME;
dd stop_watch() {
    // 経過時間をミリ秒単位で返す.
    struct timespec end_time;
    clock_gettime(CLOCK_REALTIME, &end_time);
    ll sec = end_time.tv_sec - START_TIME.tv_sec;
    ll nsec = end_time.tv_nsec - START_TIME.tv_nsec;
    return 1000 * (dd)sec + (dd)nsec / (1000000);
}

////////////////////////////////////////////////

ll RHO;
ll R = (ll)1e9;
dd NIL = -10;
ll SUCCESS_CNT = 0;

ll TURN = 0;
bool in_check(l_l P){
    if(abs(P.fi)>R || abs(P.se)>R)return false;
    return P.fi*P.fi + P.se*P.se <= R * R;
}
l_l ANS;
dd output(l_l P){
    TURN++;
    if(TURN == 1001){
        DEB(RHO);
        DEB(SUCCESS_CNT);
        exit(0);
    }
    ll x=P.fi;
    ll y=P.se;
    
    if(!in_check(P)){
        cerr<<"ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        cerr<<"ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        cerr<<"ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    }
    assert(in_check(P));
    cout<<x<<" "<<y<<endl;
    fflush(stdout);
    ll r;cin>>r;
    if(r==0){
        dd theta;cin>>theta;
        return theta;
    }else{
        SUCCESS_CNT++;
        cin>>ANS.fi>>ANS.se;
        
        if(r==2){
            cerr<<"congratulation!"<<endl;
            DEB(RHO);
            DEB(SUCCESS_CNT);
            exit(0);
        }
    }
    return NIL;
}
bool nil(dd x){
    return abs(x-NIL)<=1;
}


struct half{
    l_l p;
    dd theta;//ラジアン表記
};
l_l add(l_l a,l_l b){
    return {a.fi+b.fi,a.se+b.se};
}
l_l move(half p,ll dis){
    assert(dis>=0);
    ll ok = 0;
    ll ng = dis + 1;
    auto C=[](half p,ll mid){
        ll dx = round(cos(p.theta) * mid);
        ll dy = round(sin(p.theta) * mid);
       // cerr<<(dx*dx+dy*dy-mid)<<" "<<dx<<" "<<dy<<" "<<mid<<" "<<p.theta<<endl;
        l_l nx = add(p.p,{dx,dy});
        return nx;
    };
    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        l_l nx = C(p,mid);
        if(in_check(nx))ok=mid;
        else ng=mid;
    }
    l_l nx = C(p,ok);
    assert(in_check(nx));
    return nx;
}

dd rad_dis(dd a,dd b){
    while(a<0)a+=2*PI;
    while(a>2*PI)a-=2*PI;
    while(b<0)b+=2*PI;
    while(b>2*PI)b-=2*PI;
    
    if(a>b)swap(a,b);
    dd ret = b-a;
    chmin(ret,a+2*PI-b);
    assert(-EPS<=ret && ret<=PI+ret);
    return ret;
}

dd dist(half a,half b){
    return sqrt(powl(a.p.fi-b.p.fi,2) + powl(a.p.se-b.p.se,2));
}
dd dist(l_l a,l_l b){
    return sqrt(powl(a.fi-b.fi,2) + powl(a.se-b.se,2));
}

dd muki(l_l a,l_l b){
    //aから見た時のbの向き
    dd dx = b.fi-a.fi;
    dd dy = b.se-a.se;
    if(abs(dx)<=EPS && abs(dy)<=EPS){
        cerr<<"error"<<endl;
    }
    return atan2(dy,dx);
}


signed main(){fastio
    clock_gettime(CLOCK_REALTIME, &START_TIME);
    ///////////////////////////////////////
    /*
    rep(i,1,10){
        dd a, b;cin>>a>>b;
        cout<<rad_dis(a,b)<<endl;
    }
     //*/
    //実験
    ////////////////////////////////////////////////////////////
    
    {
        dd rho;cin>>rho;
        RHO = round(rho * 1000);
    }
    
    
    auto random=[](){
        l_l p = {R,R};
        while(!in_check(p)){
            p.fi = rand(-R,R);
            p.se = rand(-R,R);
        }
        return p;
    };
    
    vector<half>data;
    auto erase=[&](){
        vector<half>nx;
        for(half x:data){
            dd the1 = muki(x.p,ANS);
            if(rad_dis(the1,x.theta)<=RHO*2e-3){
                
            }else{
                nx.pb(x);
            }
        }
        
        data = nx;
    };
    
    rep(i,1,300){
        l_l pos = random();
        dd theta = output(pos);
        if(nil(theta)){
            erase();
            continue;
        }
        data.pb({pos,theta});
    }
    struct D{
        vl_l poss;
        vl tai;
        dd score;
    };
    ll sz = data.size();
    D now;
    rep(i,1,50-SUCCESS_CNT){
        now.poss.pb(random());
    }
    now.tai.resize(sz);
    rep(i,0,sz-1){
        ll pos=-1;
        dd mindis = inf;
        rep(j,0,now.poss.size()-1){
            dd dis = dist(now.poss[j],data[i].p);
            if(mindis>dis){
                pos = j;
                mindis = dis;
            }
        }
        assert(pos!=-1);
        now.tai[i] = pos;
    }
    auto calc_score=[&](D d){
        dd score = 0;
        rep(i,0,(int)d.tai.size()-1){
            score += 1/(rad_dis(data[i].theta,muki(data[i].p,d.poss[d.tai[i]]))) * powl(dist(d.poss[d.tai[i]],data[i].p),2);
        }
        return score;
    };
    now.score = calc_score(now);
    rep(loop,1,1000000){
        D nx = now;
        if(loop%2==0){
            ll pos = rand(0,now.poss.size()-1);
            nx.poss[pos] = move({nx.poss[pos],randdouble(0,2*PI)},1e6);
        }else{
            ll pos = rand(0,now.tai.size()-1);
            nx.tai[pos] = rand(0,(int)nx.poss.size()-1);
        }
        nx.score = calc_score(nx);
        if(now.score<nx.score){
            now = nx;
            cerr<<loop<<" "<<nx.score<<endl;
        }
    }
    for(l_l p:now.poss){
        output(p);
    }
    
    
    {
        cerr<<"終了時間は "<<stop_watch()<<"ms"<<endl;
    }
    return 0;
}
