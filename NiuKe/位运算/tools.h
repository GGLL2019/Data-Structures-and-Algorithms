//
// Created by snow on 19-9-3.
//

#ifndef ZHI_TOOLS_H
#define ZHI_TOOLS_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <deque>
#include <cstring>
#include <limits.h>


template <typename T1, typename T2>
void cout_map(std::map<T1, T2> m)
{
    for (auto mm:m) {
        std::cout << mm.first << "\t" << mm.second << "|\n";
    }
}

template <typename T>
void cout_array(T* array, int size)
{
    for (int i=0; i<size; i++) {
        std::cout << array[i] << "\t";
    }
    std::cout << "\n";
}

template <typename T>
void cout_vector(std::vector<T> vector_array)
{
    for (auto v:vector_array) {
        std::cout << v << "\t";
    }
    std::cout << "\n";
}

template <typename T>
void cout_stack(std::stack<T> stk)
{
    int n = stk.size();
    for (int i = 0; i < n; ++i) {
        std::cout << stk.top() << "\t";
        stk.pop();
    }
    std::cout << std::endl;
}

template <typename T>
std::vector<T> array_to_vector(T *array, int size)
{
    std::vector<T> vv(size);
    for (int i = 0; i < size; ++i) {
        vv[i] = array[i];
    }

    return vv;
}

template <typename T>
std::stack<T> array_to_stack(T* arr, int size)
{
    std::stack<T> stk;
    for (int i = 0; i < size; ++i) {
        stk.push(arr[i]);
    }
    return stk;
}

template <typename T>
void cout_deque(std::deque<T> dq)
{
    int n = dq.size();
    for (int i = 0; i < n; ++i) {
        std::cout << dq.front() << "\t";
        dq.pop_front();
    }
    std::cout << std::endl;
}


std::vector<std::string> str_decompose(std::string s){

    std::vector<std::string> vec_s;
    int size = s.size();
    std::string s_tmp = "";
    for (int i = 0; i < size; ++i) {
        char c = s[i];
        if (c == '!'){
            vec_s.push_back(s_tmp);
            s_tmp.clear();
        } else{
            s_tmp += c;
        }
    }

    return vec_s;
}


#endif //ZHI_TOOLS_H
