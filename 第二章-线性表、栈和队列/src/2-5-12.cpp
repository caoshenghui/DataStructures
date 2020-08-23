// File:    2-5-12.cpp
// Author:  csh
// Date:    2020/08/23
// ===================


#include <iostream>
#include <stack>
using namespace std;


double Recusion(int n){
    if(n == 1)
        return 1.0;
    else
        return ((n % 2) ? 1 : -1) * 1.0 / n + Recusion(n-1);
}

// 没弄懂怎么用栈，感觉写个循环就解决了
double NotRecusion(int n){
    if(n == 1)
        return 1.0;
    stack<double> s = stack<double>();
    s.push(1.0);
    for(int i = 2; i <= n; i++){
        double sign;
        sign = (i % 2) ? 1.0 : -1.0;
        double tmp;
        tmp = s.top();
        s.pop();
        s.push(sign/i + tmp);
    }
    return s.top();
}


int main(){
    double ret1 = Recusion(3);
    double ret2 = NotRecusion(3);
    cout << ret1 << endl;
    cout << ret2 << endl;
    return 0;
}
