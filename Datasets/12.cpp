
using namespace std;
//C headers
int main()
{
    input;
    int64 t=IL;
    int64 oc=1;
    while(oc<=t)
    {
        int64 n=IL, m=IL;
        deque<int> d;
        OC(oc++);
        while(m--)
        {
            string s=IS;
            if(s=="pushLeft")
            {
                int64 p=IL;
                if(d.size()<n){
                    d.push_front(p);
                    pf("Pushed in left: %ld\n",p);
                }
                else
                    pf("The queue is full\n");
            }
            if(s=="pushRight")
            {
                int64 p=IL;
                if(d.size()<n){
                    d.push_back(p);
                    pf("Pushed in right: %ld\n",p);
                }
                else
                    pf("The queue is full\n");
            }
            if(s=="popLeft")
            {
                if(d.size()>0){
                    int64 data = d.front();
                    d.pop_front();
                    pf("Popped from left: %ld\n",data);
                }
                else
                    pf("The queue is empty\n");
            }
            if(s=="popRight")
            {
                if(d.size()>0){
                    int64 data = d.back();
                    d.pop_back();
                    pf("Popped from right: %ld\n",data);
                }
                else
                    pf("The queue is empty\n");
            }
        }
    }
    return 0;
}
