using namespace std;

#include <bits/stdc++.h>

//Problem wise define.....
//long tree[100002];
void update(long tree[], long idx, long n, long value)
{
    while(idx<=n)
    {
        tree[idx]+=value;
        idx+=idx & (-idx);
    }
}
long query(long tree[], long idx)
{
    long sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=idx&(-idx);
    }
    return sum;
}
int main()
{
    input;
//    double cl=clock();
    long t=IL,cs=0;
    while(t--)
    {
        long n=IL,q=IL;
        long tree[n+2];
        f(0,n+1,1) tree[i]=0;
        f(1,n,1){
        long a=IL;
        update(tree,i,n,a);
        }
        OC(++cs);
        f(1,q,1)
        {
            int p=II;
            if(p==1)
            {
                long idx=II;
                long result= query(tree,idx+1)-query(tree,idx);
                pf("%ld\n",result);
                update(tree, idx+1, n, -result);
            }
            else if(p==2)
            {
                long idx=IL, value=IL;
                update(tree,idx+1,n,value);
            }
            else if(p==3)
            {
                long idxi=IL, idxj=IL;
                pf("%ld\n",query(tree,idxj+1)-query(tree, idxi));
            }
        }

    }
//    cl=clock()-cl;
//    pf("Total Execution time: %lf\n",cl/CLOCKS_PER_SEC);
    return 0;
}
