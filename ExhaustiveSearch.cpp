#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <utility>
#include <string>

using namespace std;

/*
bool search(vector<int > A, int m){
    int t = 0;
    for(int i = 0; i < A.size(); i++){
        t = 0;
        t += A[i];
        for(int j = i + 1; j < A.size(); j++){
            if(t == m){
                return true;
            }
            t += A[j];
        }        
    }

    return false;
}
*/

int solve(vector<int > A, int i, int m, int n){
    if(m == 0){
        return 1;
    } 
    if(i >= n){
        return 0;
    }
    
    int res = solve(A, i + 1, m, n) || solve(A, i + 1, m - A[i], n);
    return res;
}

//bitで全探索して求めるやつ
bool combination(int n, vector<int > A, int m){
    //
    //組み合わせの最大
    //int x = 1;
    //for(int i = 0; i < n; i++){
    //    x = x << 1;
    //    x = x | 1;
    //    //std::cout << x << std::endl;
    //}
    int sum = 0;
    for(int i = 0; i < (1<<n); ++i){
        //td::cout << i << std::endl;
        for(int j = 0; j < n; ++j){
            //特定の箇所が勃っているか？
            if(i & (1<<j)){
                sum += A[j];
                
            }
        }
        if(sum == m){
            return true;
        }
        //初期化
        sum = 0;
    }

    return false;
}



int main(){

    int n = 0;
    cin >> n;
    vector<int > A(n , 0);

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    int q = 0;
    cin >> q;

    vector<int > m(n , 0);

    for(int i = 0; i < q; i++){
        cin >> m[i];
    }

    std::cout << "再帰" << std::endl;
    for(int i = 0; i < q; i++){
        if(solve(A, 0, m[i], n) == true){
            std::cout << "yes" << std::endl;
        }else{
            std::cout << "no" << std::endl;
        }
    }

    std::cout << "bit全探索" << std::endl;
    for(int i = 0; i < q; i++){
        if(combination(n, A, m[i]) == true){
            std::cout << "yes" << std::endl;
        }else{
            std::cout << "no" << std::endl;
        }
    }

    //combination(5);

}