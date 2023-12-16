#include<iostream>
using namespace std;

template <class T, T nv>
struct node
{
    int x, y;
    node<T,nv> *d, *r;
    T v;
    node(int i, int j, T val)
    {
        x=i; y=j; v=val;
    }
};

template <class T, T nv>
struct ops;

template <class T, T nv>
struct SM
{
    int x_limit, y_limit;
    node<T,nv> **A, **B;
    SM(int x, int y)
    {
        x_limit=x; y_limit=y;
        A = new node<T,nv>*[x];
        B = new node<T,nv>*[y];
        for(int i=0; i<x; i++)
            A[i]=0;
        for(int i=0; i<y; i++)
            B[i]=0;
    }
    
    bool find_x(int c, node<T,nv> **&p)
    {
        for(;
            *p && (*p)->x < c;
            p = &((*p)->r) );
        
        if( *p && (*p)->x == c)
            return 1;
        return 0;
    }
    
    bool find_y(int c, node<T,nv> **&p)
    {
        for(;
            *p && (*p)->y < c;
            p = &((*p)->d) );
        
        if( *p && (*p)->y == c)
            return 1;
        return 0;
    }
    
    void set(int cx, int cy, T val)
    {
        if(cx>=x_limit || cy>=y_limit)
            return;
        
        node<T,nv> **px = &(B[cy]), **py = &(A[cx]);
        bool found1 = find_x(cx,px), found2 = find_y(cy, py);
        
        if(found1 && found2)
        {
            if(val != nv) //change val
                (*px)->v = val;
            else //remove
            {
                node<T,nv> *t = *px;
                *px = t->r;
                *py = t->d;
                delete t;
            }
        }
        else
            if(val != nv) //insert
            {
                node<T,nv> *tx = *px, *ty = *py;
                *px = new node<T,nv>(cx,cy,val);
                *py = *px;
                (*px)->d = ty;
                (*px)->r = tx;
            }
    }
    
    T get(int cx, int cy)
    {
        node<T,nv> **px = &(B[cy]);
        if(find_x(cx,px))
            return (*px)->v;
        return nv;
    }
    
    ops<T,nv> operator () (int x, int y);
    
    
};

template<class T, T nv>
struct ops
{
    int i,j;
    SM<T,nv> *mp;
    ops(int x, int y, SM<T,nv> *p)
    {
        i=x; j=y; mp=p;
    }
    
    operator int ()
    {
        return mp->get(i, j);
    }
    
    void operator = (T v)
    {
        mp->set(i, j, v);
    }
    
    
};

template<class T, T nv>
ops<T,nv> SM<T,nv>::operator () (int x, int y)
{
    return ops(x,y,this);
}



int main()
{
    SM<int, 0> m(4,4);
    
    // Test setting and getting values
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            m(i,j) = i*j;
            //cout << "m(" << i << "," << j << ") = " << m(i,j) << "\n";
        }
    }
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            //m(i,j) = i*j;
            cout << "m(" << i << "," << j << ") = " << m(i,j) << "\n";
        }
    }
    
    // Test updating values
    m(2,3) = 9;
    //m(2,1) = 3;
    cout << "After updating, m(2,3) = " << m(2,3) << "\n";
    
    // Test setting a value to 0 (delete)
    m(2,3) = 0;
    cout << "After deleting, m(2,3) = " << m(2,3) << "\n";
    m(0,0) = 1;
    cout << m(0,0) << "\n";
    
    return 0;
}
