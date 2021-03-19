/*************************************************************/
// For using "l/L"-prefixed(introduced in C99) scanf/printf 
// format specifiers (i.e. %lld, %Lf, etc.) in MinGW environment. 
// If this macro is not defined, MinGW complier will use the
// scanf/printf functions implemented in Microsoft C Runtime Library
// which expected prefixes "I64/I32" which doesn't match C99 Standard.
#define __USE_MINGW_ANSI_STDIO 1

// For jury which unsupports C++11
#if __cplusplus < 201103L
 
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;
 
#define ffor(_var, _begin, _end, ...) \
    for(__typeof__(_end) _var = _begin; _var < _end; __VA_ARGS__)
#define rfor(_var, _rbegin, _rend, ...) \
    for(__typeof__(_rbegin) _var = _rbegin; _var > _rend; __VA_ARGS__)
#define cfor(_var, _cbegin, _cend, ...) \
    for(__typeof__(_cend) _var = _cbegin; _var != _cend; __VA_ARGS__)
 
#else
 
#include <bits/stdc++.h>
using namespace std;
 
#define ffor(_var, _begin, _end, ...) \
    for(decay<decltype(_end)>::type _var = _begin; _var < _end; __VA_ARGS__)
#define rfor(_var, _rbegin, _rend, ...) \
    for(decay<decltype(_rbegin)>::type _var = _rbegin; _var > _rend; __VA_ARGS__)
 
#endif
 
using ll = long long;
using ld = long double;
#define ABS(x) ((x) > 0 ? (x) : -(x))

// 0x3f3f3f3f * 2 < INT_MAX = 0x7fffffff
// memset(a, 0x3f, sizeof(a))
const int INF = 0x3f3f3f3f;

#ifdef LOCAL
#define __DEBUG__
#endif
 
#ifdef __DEBUG__
#if defined _WIN32
#include <windows.h>
inline std::ostream& __YELLOW__(std::ostream &s) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, 
         FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    return s;
}
inline std::ostream& __WHITE__(std::ostream &s) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, 
       FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    return s;
}
inline std::ostream& __RED__(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hStdout, 
                FOREGROUND_RED|FOREGROUND_INTENSITY);
    return s;
}
#elif defined __linux__ || defined __APPLE__
#define __YELLOW__ "\033[33;1m"
#define __WHITE__ "\033[0m"
#define __RED__ "\033[31;1m"
#endif
#endif
 
#ifdef __DEBUG__
#define ar2vec(_begin, _end) \
    vector<decay<iterator_traits<decltype(_begin)>::value_type>::type>(_begin, _end)
#define debug(x...) \
    do { cout << __YELLOW__ << #x << " -> "; err(x); } while(0)
void err() { cout << __WHITE__ << endl; }
template<typename T, typename... A>
void err(T a, A... x) { cout << __RED__ << a << __YELLOW__ << ' '; err(x...); }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for(auto& v : a) cout << __RED__ << v << __YELLOW__ << ' '; err(x...); }
#else
#define ar2vec(...)
#define debug(...)
#endif

#ifdef __DEBUG__
template <typename T, typename U>
ostream &operator << (ostream &out, const pair<T, U> &p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}
template <typename T>
ostream &operator << (ostream &out, const vector<T> &v) {
    out << "{";
    for(int i = 0; i < v.size(); i++)
        out << v[i] << (i == v.size() - 1 ? "" : ", ");
    out << "}";
    return out;
}
template <typename T>
ostream &operator << (ostream &out, const set<T> &s) {
    out << "{";
    for(const auto &it : s)
        out << it << " ";
    out << "}";
    return out;
}
template <typename T>
ostream &operator << (ostream &out, const unordered_set<T> &s) {
    out << "{";
    for(const auto &it : s)
        out << it << " ";
    out << "}";
    return out;
}
#endif
/*************************************************************/

int main() {
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#else
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif

    // insert your code here.

    return 0;
}