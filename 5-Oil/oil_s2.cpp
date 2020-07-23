#include "oil.h"
//#include "oil-openVer.h"

int seek_B(int a,int b){
    int result = observe(a,(a+b)/2);
    if(result==2){
        seek_B(a,(a+b)/2);
    }
    else if(result==0){
        seek_B((a+b)/2+1,b);
    }
    else{
        return a;
    }
}

int seek_E(int a,int b){
    int result = observe((a+b)/2+1,b);
    if(result==2){
        seek_E((a+b)/2+1,b);
    }
    else if(result==0){
        seek_E(a,(a+b)/2);
    }
    else{
        return b;
    }
}
int main(){
    initial();
    int N = oil_size();
    oil_report(seek_B(0,N-1),seek_E(0,N-1));
    return 0;
}
