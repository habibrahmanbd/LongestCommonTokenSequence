using namespace std;
//C headers
#include <cstdio>
#define mx 1000000
int64 arr[mx];
int64 tree[mx*3];
void init(int64 node, int64 b,int64 e)
{
    if(b==e){
        tree[node] = arr[b];
        return;
    }
    int64 left = node*2;
    int64 right = (2*node)+1;
    int64 mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node]=MIN(tree[left],tree[right]);  // Every Node Containing the minimum values of their child
}
int64 query(int64 node, int64 b, int64 e, int64 i, int64 j)
{

    if(i>e||j<b) return INF;
    else if(b>=i&&e<=j) return tree[node];
    int64 left = node*2;
    int64 right = (2*node)+1;
    int64 mid = (b+e)/2;
    int64 p1 = query(left, b, mid, i, j);
    int64 p2 = query(right, mid+1, e, i, j);
    return MIN(p1,p2);
}
int main()
{

   input;
    int t=II;
    int cs=1;
    while(t--){
    int64 n=IL,q=IL;
    FOR(1,n,1)
    arr[i]=IL;
    init(1,1,n);
    OC(cs++);
//    PF("\n");
    while(q--){
    int64 i=IL, j=IL;
    int64 q_res = query(1,1,n, i,j);  //Query for the minimum value in the array
    PF("%ld\n",q_res);
    }
    }
    return 0;
}
